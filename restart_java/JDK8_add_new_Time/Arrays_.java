package JDK8_add_new_Time;

import java.util.Arrays;
import java.util.function.IntToDoubleFunction;

public class Arrays_ {
    //操作数组的工具类
    /*
        public static String toString(类型[] arr) 返回数组的内容
        public static int[] copyOfRange(类型[] arr,起始索引，结束索引) 拷贝数组（指定范围）
        public static copyOf(类型[] arr,int newLength)    拷贝数组
        public static setAll(double[] array,IntDoubleFunction generator)    把数组中的原数据改为新数据
        public static void sort(类型[] arr)   对数组进行排序（默认是升序排序）
     */
    /*
        操作对象的方法：
        方案一：让该对象的类实现Comparable(比较规则)接口，然后重写compareTo方法，自己指定比较规则
        方案二：使用下面的sort方法，创建Comparator比较器接口的匿名内部类对象，然后自己指定比较规则
        public static <T> void sort(T[] arr,Comparator<? super T> c)对数组进行排序(支持自定义排序规则)
     */
    public static void main(String[] args) {
        double[] prices = {99.8,128,648};
        Arrays.setAll(prices, new IntToDoubleFunction() {
            //数组中所有的元素×0.8再重新存回去
            @Override
            //value代表数组索引
            public double applyAsDouble(int value) {
                return prices[value]*0.8;
            }
        });
    }
}
