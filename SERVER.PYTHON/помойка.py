import requests


# Авторизуйтесь
requests.post(
    "http://localhost:5000/login",
    json={"username": "st4kan", "password": "4321"}
)
"""
requests.post(
    "http://localhost:5000/chat",
    json={"session_id":
              "привет помоги мне плохо я хачу умерец"}
)
"""
