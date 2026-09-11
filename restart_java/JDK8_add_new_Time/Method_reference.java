package JDK8_add_new_Time;

public class Method_reference {
      /*
            静态方法引用:
            类名::静态方法
            如果某个Lambda表达式里只是调用一个静态方法，并且前后参数的形式一致，就可以使用
            Arrays.sort(students,(o1,o2) -> o1.getAge() - o2.geAge());
            ||
            Arrays.sort(students,(o1,o2) -> CompareByData.compareByAge(o1,o2));
            ||
            Arrays.sort(students, CompareByData::compareByAge);
            ----------------------------------------------------
            实例方法引用：
            对象名::实例方法
            如果某个Lambda表达式里只是调用一个实例方法，并且前后参数的形式一致，就可以使用
            具体实现同上
            ----------------------------------------------------
            特定类型方法引用：
            类型::方法
            如果某个Lambda表达式里只是调用一个实例方法，并且前面参数类别的第一个参数式作为方法的主调，
            后面的所有参数都是作为该实例方法的入参的，则此时就可以使用特定类型的方法引用
            Arrays.sort(names,(o1,o2) -> o1.compareToIgnoreCase(o2));
            ||
            Arrays.sort(names,String::compareToIgnoreCase);
            -----------------------------------------------------
            构造器引用：
            类目::new
            如果某个Lambda表达式里只是创建对象，并且前后参数情况一致，就可以使用构造器引用
       */
}
