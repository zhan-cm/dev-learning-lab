import numpy as np
data=np.array([1,2,3,4])
# 保存数组到文件
np.save('my_array.npy', data)

# 加载数组
loaded_data = np.load('my_array.npy')