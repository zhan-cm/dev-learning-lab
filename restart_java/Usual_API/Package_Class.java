package Usual_API;

import java.util.ArrayList;

public class Package_Class {
    /**
     * 基本数据类型           对应的包装类（引用数据类型）
     * byte                 Byte
     * short                Short
     * int                  Integer
     * long                 Long
     * char                 Charcater
     * float                Float
     * double               Double
     * boolean              Boolean
     */

    //基本类型的数据包装成对象的方案
    //public static integer valueOf(int i)
    public static void main(String[] args) {
        //自动装箱
        Integer a1 = 12;
        //自动拆箱
        int a2 =a1;

        //泛型不支持基本数据类型
        ArrayList<Integer> a = new ArrayList<>();
    }

    //把基本数据类型数据转换成字符串类型
    //public static String toString(double d)
    //public String toString()

    //把字符串类型数据转换成本身对应的数据类型
    //public static int parseInt(String s)
    //public static integer valueOf(String s)
}
