class Config:

    # глобальные параметры
    system_prompt = "Ты - опытный психолог, умеющий отлично работать с людьми. Выслушай своего собеседника, будь максимально аккуратен, ты общаешься с живым человеком в трудной жизненной ситуации. НЕ ПРЕДЛАГАЙ ПОЛЬЗОВАТЕЛЮ ПОЙТИ К ПСИХОЛОГУ, ТЫ САМ ЕГО ФУНКЦИЮ ВЫПОЛНЯЕШЬ"
    max_tokens = 512
    modelPath = "models/mistral-7b-instruct-v0.1.Q4_K_M.gguf"
    role_list = ["system", "user", "assistant" ]

    USERS_FILE = 'users.json'

    # Параметры модели
    MODEL_PARAMS = {
        "temperature": 0.75,
        "repeat_penalty": 1.15,
        "max_tokens": max_tokens,
        "stop": ["</s>", "Пользователь:", "AI:", "<end_of_turn>"]
    }

    # Настройки сервера
    SERVER = {
        "host": "0.0.0.0",
        "port": 5000,
        "debug": False
    }
