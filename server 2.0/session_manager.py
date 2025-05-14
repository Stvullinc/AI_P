import json
import os
from config import Config


class SessionManager:
    def __init__(self):
        # Создаем директорию для историй, если ее нет
        os.makedirs(Config.USER_HISTORY_DIR, exist_ok=True)

    def get_history_path(self, username):
        # Генерируем путь к файлу истории пользователя
        return os.path.join(Config.USER_HISTORY_DIR, f"{username}_history.json")

    def load_history(self, username):
        # Загрузка истории из персонального файла
        history_path = self.get_history_path(username)
        try:
            with open(history_path, 'r') as f:
                return json.load(f)
        except FileNotFoundError:
            return [{"role": Config.role_list[0], "content": Config.system_prompt}]

    def save_history(self, username, history):
        # Сохранение истории в персональный файл
        history_path = self.get_history_path(username)
        with open(history_path, 'w') as f:
            json.dump(history, f, ensure_ascii=False, indent=2)


session_manager = SessionManager()  # Создаем экземпляр менеджера сессий