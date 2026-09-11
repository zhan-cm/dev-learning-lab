package JDK8_add_new_Time;

public class Lambda_ {
    //Lambda表达式是JDK8开始新增的一种语法形式；作用：用于简化匿名内部类的代码写法
    /*
        格式：
            (被重写方法的形参列表)->{
                被重写方法的方法体代码
            }

        注意：lambda表达式只能简化函数式接口的匿名内部类(有且仅有一个抽象方法的接口)
     */
    public static void main(String[] args) {
//        Swimming s = new Swimming() {
//            @Override
//            public void swim() {
//                System.out.println("swim");
//            }
//        };
//        s.swim();

        Swimming s = ()->{
            System.out.println("swim");
        };
        s.swim();
        /*
            Lambda表达式的省略写法（进一步简化Lambda表达式的写法）
                1.参数类型可以省略不写
                2.如果只有一个参数，参数类型可以省略，同时（）也可以省略
                3.如果Lambda表达式中的方法体代码只有一行代码，可以省略大括号不写，同时要省略分号！
                  此时，如果这行代码是return语句也必须去掉return不写
         */
    }
}

interface Swimming{
    void swim();
}