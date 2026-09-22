###计算数组的平均值
'''
numpy.mean(arr, axis=None, dtype=None, out=None): 计算数组的平均值。
参数axis表示沿着哪个轴进行计算，默认为None，表示计算整个数组的平均值；
dtype表示返回结果的数据类型，默认为float64；
out表示将结果存储在指定的数组中,
一般情况下，传个数组进去就可以了，其他的用默认的就好了，其它的方法也是一样，我不赘述
'''
import numpy as np
data=[1,5,6,9]
mindle=np.mean(data)
print(mindle)
print()


###计算数组的中位数
'''
numpy.median(arr, axis=None, out=None): 计算数组的中位数。
参数axis和out的含义与numpy.mean()相同
'''
import numpy as np
data=[1,5,6,9]
data1=np.median(data)
print(data1)

###计算数组的标准差
'''
numpy.std(arr, axis=None, dtype=None, out=None): 计算数组的标准差。
参数axis、dtype和out的含义与numpy.mean()相同
'''

###计算数组的方差
'''
numpy.var(arr, axis=None, dtype=None, out=None): 计算数组的方差。
参数axis、dtype和out的含义与numpy.mean()相同。
'''

###计算数组的最小值
'''
numpy.min(arr, axis=None, out=None): 计算数组的最小值。
参数axis和out的含义与numpy.mean()相同。
'''

###计算数组的最大值
'''
numpy.max(arr, axis=None, out=None): 计算数组的最大值。
参数axis和out的含义与numpy.mean()相同
'''

###计算数组的元素之和
'''
numpy.sum(arr, axis=None, dtype=None, out=None): 计算数组的元素之和。
参数axis、dtype和out的含义与numpy.mean()相同。
'''

###计算数组的元素乘积
'''
numpy.prod(arr, axis=None, dtype=None, out=None): 计算数组的元素乘积。
参数axis、dtype和out的含义与numpy.mean()相同
'''

###计算数组的累积和
'''
numpy.cumsum(arr, axis=None, dtype=None, out=None): 计算数组的累积和。
参数axis、dtype和out的含义与numpy.mean()相同。
'''
