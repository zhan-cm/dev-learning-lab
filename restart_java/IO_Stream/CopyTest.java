package IO_Stream;

import java.io.*;

public class CopyTest {
    public static void main(String[] args) throws IOException {
        //需求复制照片
        InputStream is = new FileInputStream("D:/resource/meinv.png");
        OutputStream os = new FileOutputStream("C:/data/meinv.png");

        //创建一个字节数组，负责转移字节数据
        byte[] bytes = new byte[1024];
        //从字节输入流中读取字节数据，写出去到字节输出流中，读多少写出去多少
        int len;
        while((len = is.read())!=-1){
            os.write(bytes,0,len);
        }
        os.close();
        is.close();
        System.out.println("复制完成！！！");
    }
}
