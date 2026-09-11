package Advanced_JAVA.Reflect;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class Method_ {
    /*
        获取类的成员方法
        Class提供了从类中获取成员方法的API
        方法
        Method[] getMethods()   获取类的全部成员方法（只能获取public修饰的）
        Method[] getDeclaredMethods()   获取类的全部成员方法（只要存在就能拿到）
        Method getMethod(String name,Class<?>... parameterTypes)    获取类的某个成员方法（只能获取public修饰的）
        Method getDeclaredMethod(String name,Class<?>... parameterTypes)    获取类额某个成员方法（只要存在就能拿到）

        成员方法的作用：依然是执行
        方法
        public Object invoke(Object obj,Object... args) 触发某哦个对象的该方法执行
        public void setAccessible(boolean flag) 设置为true，表示禁止检查访问控制（暴力反射）
     */
    public static void main(String[] args) throws NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        Class c = Student.class;

        Method[] methods = c.getDeclaredMethods();

        Method m = c.getDeclaredMethod("study", String.class);
        System.out.println(m);

        Student s= new Student();
        m.setAccessible(true);
        Object o = m.invoke(s);
        System.out.println(o);
    }
}
