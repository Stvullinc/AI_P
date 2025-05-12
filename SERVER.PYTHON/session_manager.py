import json
import os
from functools import lru_cache
from config import Config

class SessionManager:
    def __init__(self, sessions_dir="sessions"):
        self.sessions_dir = sessions_dir
        os.makedirs(sessions_dir, exist_ok=True)

    def get_session_path(self, session_id: str) -> str:
        return os.path.join(self.sessions_dir, f"{session_id}.json")

    @lru_cache(maxsize=100)  # кэш последних 100 сессий
    def load_session(self, session_id: str) -> list:
        try:
            with open(self.get_session_path(session_id), 'r') as f:
                return json.load(f)
        except (FileNotFoundError, json.JSONDecodeError):
            return [
                {
                    "role": Config.role_list[0], # system
                    "content": Config.system_prompt
                }
            ]

    def save_session(self, session_id: str, history: list):
        with open(self.get_session_path(session_id), 'w') as f:
            json.dump(history[-20:], f, ensure_ascii=False, indent=2)  # Сохраняем только последние 10 сообщений


# Инициализация менеджера
session_manager = SessionManager()
