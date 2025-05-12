from flask import Flask, request, jsonify
from flask_limiter import Limiter
from flask_limiter.util import get_remote_address
from model_loader import model, model_lock
from session_manager import session_manager
import uuid
from config import Config
import logging
from logging.handlers import RotatingFileHandler
import json




USERS_FILE = Config.USERS_FILE

# логи
logger = logging.getLogger('my_app')
logger.setLevel(logging.INFO)

# обработчик для всех логов
handler = RotatingFileHandler(
    'app.log',
    maxBytes=1000000,
    backupCount=3,
    encoding='utf-8'
)

handler.setFormatter(logging.Formatter(
    '%(asctime)s - %(levelname)s - %(message)s'
))
logger.addHandler(handler)

llama_logger = logging.getLogger('llama.cpp')
llama_logger.propagate = False  # Отключаем передачу родительским логгерам
llama_logger.addHandler(handler)
llama_logger.setLevel(logging.INFO)


# запуск сервиса
app = Flask(__name__)
# лимит запросов к модели
limiter = Limiter(
    app=app,
    key_func=get_remote_address,
    storage_uri="memory://",
    default_limits=["200 per hour",]
)

# общие логи
handler = RotatingFileHandler(
    'app.log',
    maxBytes=1000000,
    backupCount=3
)
handler.setLevel(logging.INFO)
app.logger.addHandler(handler)

def load_users():
    with open(USERS_FILE, 'r') as f:
        return json.load(f)

def save_users(users):
    with open(USERS_FILE, 'w') as f:
        json.dump(users, f, indent=4)


@app.route('/register', methods=['POST'])
@limiter.limit("20 per minute")
def register():
    data = request.json
    user_ip = request.remote_addr
    users = load_users()
    username = data.get('username', 'unknown')

    if data['username'] in users:
        logger.warning(
            f"[ОШИБКА РЕГИСТРАЦИИ] - пользователь уже существует: IP - {user_ip} ###### Username - {username}"
        )
        return jsonify({"error": "вы уже зарегистрированы"}), 400

    users[data['username']] = {
        "password": data['password'] # принимает после хеширования
    }
    save_users(users)
    logger.info(
        f"[РЕГИСТРАЦИЯ УСПЕШНА]: IP - {user_ip} ###### Username - {username}"
    )
    return jsonify({"success": True})


@app.route('/login', methods=['POST'])
@limiter.limit("20 per minute")
def login():
    data = request.json
    user_ip = request.remote_addr
    username = data.get('username', 'unknown')
    users = load_users()
    user = users.get(username)

    if data['username'] not in users:
        logger.warning(
            f"[ОШИБКА ВХОДА] - пользователя не существует: IP - {user_ip}"
        )
        return jsonify({"error": "вас не существует"}), 400

    if not user or user['password'] != data['password']:
        logger.warning(
            f"[ОШИБКА ВХОДА] - неверный пароль: IP - {user_ip} ###### Username - {username}"
        )
        return jsonify({"error": "неверный пароль"}), 401
    logger.info(
        f"[УСПЕШНЫЙ ВХОД]: IP - {user_ip} ###### Username - {username}"
    )
    return jsonify({"success": True})


@app.errorhandler(429)
def login_limit_handler(e):
    user_ip = request.remote_addr

    logger.warning(f"[ПРЕВЫШЕНИЕ ЛИМИТА] - IP: {user_ip}")
    return jsonify({"error": str(e)}), 429


@app.route('/chat', methods=['POST'])
@limiter.limit("10 per minute")
def chat():
    try:
        data = request.get_json()
        session_id = data.get('session_id', str(uuid.uuid4()))
        user_input = data['message']

        # загрузка истории переписки
        history = session_manager.load_session((session_id))
        history.append({
                "role": Config.role_list[1],  # user
                "content": user_input
            })
        # генерация ответа
        with model_lock:
            response = model.create_chat_completion(
                messages = history,
                **Config.MODEL_PARAMS
            )

        ai_response = response['choices'][0]['message']['content']
        history.append({
            "role": Config.role_list[2],  # assistant
            "content": ai_response
        })

        # сохранение сессии
        session_manager.save_session(session_id, history)

        return jsonify({
            "session_id": session_id,
            "response": ai_response,
            "status": "success"
        })

    except Exception as e:
        logger.error(
            f"[ОШИБКА]: IP - {request.remote_addr}  ###### текст ошибки - {str(e)}"
        )
        return jsonify({"error": str(e)}), 500




if __name__ == '__main__':
    app.run(
        host=Config.SERVER['host'],
        port=Config.SERVER['port'],
        debug=Config.SERVER['debug']
    )