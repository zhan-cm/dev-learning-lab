import numpy as np
###2.1数组维度 ndim
''' ndim属性代表数组维度'''
data = np.array([[1,2,3],[1,2,3]])
print(data.ndim)
print()


###2.2数组形状shape
''' shape属性代表数组形状，可以这么理解shape是各个方向的维度(ndim)'''
print(data.shape)
print()

### 2.3数组中元素个数
print(data.size)
print()


###2.4 数组的数据类型 dtype
print(data.dtype)
print()