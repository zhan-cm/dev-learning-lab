import torch
print(torch.__version__)          # 应输出 2.5.1+cu121
print(torch.cuda.is_available())  # 应返回 True
print(torch.cuda.get_device_name())  # 输出显卡型号（如 NVIDIA RTX 3060）