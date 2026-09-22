###1.1创建一维数组
import numpy as np
data=np.array([1,2,3,4])
print(data)
print()


###1.2创建二位数组（矩阵）array
import numpy as np
data=np.array([[1,2,3,4],[4,5,6,7]])
print(data)
print()


###1.3创建全0数组
'''shape属性代表形状 shape（2，5） 就代表创建2行5列的全零数组'''
'''
创建全零数组的用途是初始化一个具有特定形状和大小的数组，其中所有元素都设置为0。
在处理图像或其他数据时，全零数组可以用作初始值或占位符。

例如，假设我们要读取一个尺寸为（255，255，255）的图片，我们可以创建一个相同维度的全零数组，
然后将图片读入该数组进行填充。这样做的好处是，我们可以直接将原始图像数据存储在全零数组中，
而无需担心数据溢出或其他问题。
'''
import numpy as np
#shape代表形状，比如我这里创建的就是5行三列的2维数组
data=np.zeros(shape=(5,3))
print(data)
print()


###1.4创建全1数组
'''
创建全1数组的用途是初始化一个具有特定形状和大小的数组，其中所有元素都设置为1。
在处理一些数学问题或算法时，全1数组可以用作初始值或占位符。

例如，假设我们要计算一个矩阵与自身的转置相乘的结果，我们可以创建一个与输入矩阵相同维度的全1数组，
然后将输入矩阵读入该数组进行填充。这样做的好处是，我们可以直接将原始矩阵数据存储在全1数组中，
而无需担心数据溢出或其他问题。
'''
import numpy as np
#shape代表形状，比如我这里创建的就是5行三列的2维数组
data=np.ones(shape=(5,3))
print(data)
print()

###1.5创建全空数组
'''创建出来的全空数组中的数据都是无限小的、无限接近于0但不是0，这方便我们数学上的一些操作'''
import numpy as np
#shape代表维度，比如我这里创建的就是5行三列的2维数组
data=np.empty(shape=(5,3))
print(data)
print()


###1.6 创建有连续序列的数组 arange
'''数组从10开始步长为2，所以创建出来数组元素就是10，12，14'''
import numpy as np
data = np.arange(10,16,2) # 10-16的数据，步长为2
print(data)
print()


###1.7 创建有连续间隔的数组 linspace
'''也可以称为线性等分向量（linear space），
在一个指定区间内按照指定的步长，将区间均等分，生成的是一个线段类型的数组。
生成的线性间隔数据中，是有把区间的两端加进去的'''
import numpy as np
# 创建线段型数据
data= np.linspace(1,10,20) # 开始端1，结束端10，且分割成20个数据，生成线段
print(data)
print()


###1.8创建随机数组
''' 创建随机数组的用途是初始化一个具有特定形状和大小的数组，其中所有元素都是随机生成的。
在处理一些需要模拟随机数据的情况时，随机数组可以用作占位符或测试数据。'''
import numpy as np
data = np.random.rand(3,4)
print(data)
print()
'''这里我们还可以用另外一种方法创建数组，这种方法很灵活，也好用
这段代码使用NumPy库创建了一个4行5列的随机整数数组，其中每个元素的值在2到5之间'''
import numpy as np
data=np.random.randint(2,5,size=(4,5))
print(data)
print()


###1.9改变数组形状
'''这个怎么理解呢，比如说你本来有一个2行3列的数组，你可以把它改成为3行2列的数组
    注意：因为数组中元素是没有改变的，所以重塑数组指定的尺寸大小是否和原本的尺寸大小一样，
大一点和小一点都会报错，2行3列的数组，你可以把它改成为3行2列的数组 ，或者1行6列，改后尺寸必须一样，
reshape本质就是原本数组中的元素按顺序展开来，然后依次填入新定义的尺寸中去.
注意 reshape后面填的是元组数据类型
'''
import numpy as np
data1=[1,2,3,4,5]
data2=[1,2,3,4,5]
data=np.array([data1,data2])
print("改之前的数组形状为:")
print(data.shape)
data=data.reshape((5,2))
print("改之后的数组形状为:")
print(data.shape)
print()


###1.10数组转置
import numpy as np
data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
data_array = np.array(data)
print("没有转置数组之前数组为：")
print(data)
print("转置数组之后数组为：")
print(data_array.T)