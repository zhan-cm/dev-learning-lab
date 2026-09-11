package Advanced_JAVA.Annotation;

public class Annotation_ {
    /*
        注解：就是Java代码里的特殊标记，比如：@Override,@Test，作用是：让其他程序根据注解来决定怎么执行该程序
        --------------------------------------------------------------

        自定义注解：就是自己定义注解
        public @interface 注解名称{
            public 属性类型 属性名() default 默认值;
        }
        特殊属性名：value
            如果注解中只有一个value属性，使用注解时，value名称可以不写！
        ---------------------------------------------------------------

        注解的原理：
            注解本质是一个接口，Java中所有注解都是继承了Annotation接口的
            @注解(...)：其实就是一个实现类对象，实现了该注解以及Annotation接口
        --------------------------------------------------------------------
        元注解：修饰注解的注解
        @Target
            作用：声明被修饰的注解只能在哪些位置使用
                @Target(ElementType.TYPE)
                TYPE,类，接口
                FIELD,成员变量
                METHOD,成员方法
                PARAMETER,方法参数
                CONSTRUCTOR,构造器
                LOCAL_VARIABLE,局部变量

        @Retention
            作用：声明注解的保留周期
            @Retention(RetentionPolicy.RUNTIME)
            SOURCE:只作用在源码阶段，字节码文件中不存在
            CLASS:保留到字节码文件阶段，运行阶段不存在
            RUNTIME:一直保留到运行阶段
        --------------------------------------------------------------
        什么是注解的解析？
            就是判断类上、方法上、成员变量上是否存在注解，并把注解里的内容给解析出来
        如何解析注解？
            指导思想：要解析谁上面的注解，就应该先拿到谁
            比如要解析类上面的注解，则应该获取到该方法成员方法的Method对象，在通过Method对象解析其上面的注解
            Class、Method、Field、Constructor、都实现了AnnotationElement接口，它们都拥有解析注解的能力

            方法
            public Annotation[] getDeclaredAnnotations()    获取当前对象上的注解
            public T getDeclaredAnnotation(Class<T> annotationClass)    获取指定的注解对象
            public boolean isAnnotationPresent(Class<Annotation> annotationClass)   判断当前对象上是否存在某个对象
     */
}
