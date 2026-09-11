package Advanced_JAVA.Junit;

public class StringUtil {
    /*
        Junit单元测试：
            具体步骤：
                将Junit框架的jar包导入到项目中（注意：IDEA集成了Junit框架，不需要手动导入）
                为需要测试的业务类，定义对应的测试类，并为每个业务方法，编写对应的测试方法（必须：公共、无参、无返回值 ）
                测试方法上必须声明@Test注解，然后在测试方法中，编写代码调用被测试的业务方法进行测试
                开始测试：选中测试方法，右键选择“Junit运行”，如果测试通过为绿色，失败为红色
     */
    public static void printNumber(String name){
        System.out.println("名字长度是："+name.length());
    }
    public static int getMaxIndex(String data){
        if(data==null){
            return -1;
        }
        return data.length();
    }
}
