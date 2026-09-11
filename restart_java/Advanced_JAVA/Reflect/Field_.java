package Advanced_JAVA.Reflect;

import java.lang.reflect.Field;

public class Field_ {
    /*
        获取类的成员变量
        Class提供了从勒种获取成员变量的方法
        方法
        public Field[] getFields()  获取类的成员变量（只能获取public修饰的）
        public Field[] getDeclaredFields()  获取类的全部成员变量（只要存在就能拿到）
        public Field getField(String name)  获取类的某个成员变量（只能获取public修饰的）
        public Field getDeclaredField(String name)  获取类的某个成员变量（只要存在就能拿到）

        获取到成员变量的作用：依然是赋值，取值
        方法
        void set(Object obj,Object value);  赋值
        Object get(Object obj)  取值
        public void setAccessible(boolean flag) 设置为true，表示禁止检查访问控制
     */
    public static void main(String[] args) throws NoSuchFieldException, IllegalAccessException {
        Class c = Student.class;

        //获取所有成员变量
        Field[] f1 = c.getDeclaredFields();
        for (Field f:f1){
            System.out.println(f.getName()+"--->"+f.getType());
        }

        //定位某个成员变量
        Field fName = c.getDeclaredField("name");
        System.out.println(fName.getName()+"--->"+fName.getType());

        //赋值
        Student s = new Student();
        fName.setAccessible(true);
        fName.set(s,"zhangsan");
        System.out.println(s);

        //取值
        String name = (String)fName.get(s);
        System.out.println(name);
    }
}
