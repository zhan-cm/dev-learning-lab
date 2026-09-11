package Advanced_JAVA.Reflect;

import java.lang.reflect.Constructor;

public class Constructor_ {
    /*
        获取类的构造器，并对其进行操作
        方法
        Constructor<?>[] getConstructor()   获取全部构造器（只能获取public修饰的）
        Constructor<?>[] getDeclaredConstructor()   获取全部构造器（只要存在就能拿到）
        Constructor<T> getConstructor(Class<?>... parameterTypes)   获取某个构造器（只能获取public修饰的）
        Constructor<T> getDeclaredConstructor(Class<?>... parameterTypes)   获取某个构造器（只要存在就能拿到）

        获取类构造器的作用：依然是初始化对象返回
        方法
        T newInstance(Object... initargs)   调用此构造器对象表示的构造器，并传入参数，完成对象的初始化并返回
        public void setAccessible(boolean flag) 设置为true，表示禁止检查访问控制（暴力反射）
     */
    public static void main(String[] args) throws NoSuchMethodException {
        Class c = Student.class;
        Constructor[] constructors = c.getConstructors();
        for(Constructor constructor: constructors){
            System.out.println(constructor.getName()+"--->"+constructor.getParameterCount());
        }

        Constructor constructor = c.getDeclaredConstructor(String.class,int.class);
        System.out.println(constructor.getName()+"--->"+constructor.getParameterCount());
    }
}
