from llama_cpp import Llama
import threading
from config import Config
import sys

class ModelSingleton:
    Isinstance = None
    lock = threading.Lock()
    def __new__(cls):
        with cls.lock:
            if not cls.Isinstance:
                cls.Isinstance = super().__new__(cls)
                cls.Isinstance.init_model()
            return cls.Isinstance

    def init_model(self):
        self.model = Llama(
            model_path=Config.modelPath,
            n_gpu_layers=35,
            n_ctx=4096,
            offload_kqv=True,
            n_threads=6,
            tensor_split=[0.8],
            verbose=False,
        )
        self.lock = threading.Lock()

model = ModelSingleton().model
model_lock = ModelSingleton().lock