import numpy as np
# 垂直堆叠
array1 = np.array([1,2,3,4])
array2 = np.array([11,22,33,44])
stacked_vertically = np.vstack((array1, array2))
print(stacked_vertically)
print("--------------------")

# 水平堆叠
stacked_horizontally = np.hstack((array1, array2))
print(stacked_horizontally)