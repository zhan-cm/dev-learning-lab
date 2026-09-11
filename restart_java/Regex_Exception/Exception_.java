package Regex_Exception;

public class Exception_ {
    /*
        运行时异常：RuntimeException及其子类，编译阶段不会出现错误提示，运行时出现的异常（如：数组索引越界异常）
        编译时异常：编辑阶段出现的错误提示（如：日期解析异常）
     */
    /*
        自定义运行时异常
            定义一个异常类继承RuntimeException
            重写构造器
            通过throw new 异常类（XXX）来创建异常对象并抛出。
            编译阶段不报错，提醒不强烈，运行时才可能出现！

        自定义编译时异常：
            定义一个异常类继承Exception
            重写构造器
            通过throw new 异常类（XXX）来创建异常对象并抛出
            编译阶段就报错，提醒更加强烈！
     */
}