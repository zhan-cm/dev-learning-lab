package Special_Document;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Properties;
import java.util.Set;

public class Properties_ {
    /*
        属性文件：
            都只能是键值对
            键不能重复
            文件后缀一般是.properties结尾的

        Properties:
            是一个Map集合（键值对集合），但是我们一般不会当集合使用
            核心作用：Properties是用来代表属性文件的，通过Properties可以读写属性文件里的内容

        使用Properties读取属性文件里的键值对数据

        构造器
        public Properties()

        方法
        public void load(InputStream is)    通过字节输入流，读取属性文件里的键值对数据
        public void load(Reader reader) 通过字符输入流，读取属性文件里的键值对数据
        public String getProperty(String key)   根据键获取值（其实就是get方法的较高）
        public Set<String> stringPropertyNames()    获取全部键的集合（其实就是ketSet方法的效果）

        =========================================================
        构造器
        public Properties() 用于构建Properties集合对象（空容器）

        方法
        public Object setProperty(String key,String value)  保存键值对数据到Properties对象中去
        public void store(OutputStream os,String comments)  把键值对数据，通过字节输出流写出到属性文件里去
        public void store(Writer w,String comments) 把键值对数据，通过字符输出流写出到属性文件里去
     */
    public static void main(String[] args) throws IOException {
        Properties properties = new Properties();

        properties.load(new FileReader("F:\\code-java\\Restart\\src\\Special_Document\\users.properties"));
        System.out.println(properties);

        System.out.println(properties.getProperty("赵敏"));

        Set<String> keys = properties.stringPropertyNames();
        for (String key : keys) {
            System.out.println(key+"======>"+ properties.getProperty(key));
        }

        System.out.println("================================================");
        properties.setProperty("zhangsan","zs");

        properties.store(new FileWriter("F:\\code-java\\Restart\\src\\Special_Document\\users.properties"),
                "i save many user!");
    }
}
