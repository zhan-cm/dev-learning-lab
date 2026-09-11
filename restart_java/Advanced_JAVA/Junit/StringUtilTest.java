package Advanced_JAVA.Junit;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.jupiter.api.Test;

public class StringUtilTest {
    @Before
    public void test1(){
        System.out.println("---test before---");
    }
    @After
    public void test2(){
        System.out.println("---test After---");
    }
    @Test
    public void testPrintNumber(){
        StringUtil.printNumber("admin");
    }
    @Test
    public void testGetMaxIndex(){
        int index1 = StringUtil.getMaxIndex(null);
        System.out.println(index1);

        int index2 = StringUtil.getMaxIndex("admin");
        System.out.println(index2);

        //断言机制：程序员可以通过预测业务方法的结果
        Assert.assertEquals("方法内部有bug",4, index2);
    }
}
