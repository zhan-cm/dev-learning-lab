package Advanced_Set_Theory;

public class List_ {
    /*
        List方法：
            void add(int index,E element)
            E remove(int index)
            E set(int index,E element)
            E get(int index)
        支持的遍历方式：
            for循环、迭代器、增强for循环、lambda表达式
     */
    /*
        ArrayList集合底层原理：
            基于数组实现的
            查询速度快：根据索引来查询数据
            删除效率低：可能需要把后面很多的数据进行前移
            添加速率极低：可能需要把后面很多数据后移或要对数组进行扩容

            1.利用无参构造器创建集合，会在底层创建一个默认长度为0的数组
            2.添加第一个元素时，底层会创建一个新的长度为10的数组
            3.存满时，会扩容1.5倍
            4.如果一次添加多个元素，1.5倍放不下，则新创建的数组的长度以实际为准
     */
    /*
        LinkedList集合底层原理：
            基于双链表实现的
            查询慢，增删相对较快，但对首尾元素进行增删改查的速度是极快的

            LinkedList新增了：很多首尾操作的特有方法
                void addFirst(E e)
                void addLast(E e)
                E getFirst()
                E getLast()
                E removeFirst()
                E removeLast()

     */
}
