package Advanced_Set_Theory;

import java.util.Arrays;

public class Variable_arguments {
    /*
        可变参数：
            就是一种特殊形参，定义在方法，构造器的形参列表里，格式是：数据类型...参数名称

        可变参数的特点和好处：
            特点：可以不传数据给它，可以传一个或者传多个数据给它，也可以传一个数组给它
            好处：常常用来灵活的接收数据
     */
    public static void main(String[] args) {
        int[] arr = {10,20,30,40};
        test();
        test(10);
        test(10,120);
        test(arr);
    }

    public static  void test(int...nums){
        System.out.println(nums.length);
        System.out.println(Arrays.toString(nums));
    }
}
