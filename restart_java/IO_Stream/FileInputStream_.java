package IO_Stream;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

public class FileInputStream_ {
    /*
        FileInputStream文件字节输入流
            以内存为基准，可以把磁盘文件中的数据以字节的形式读入到内存中去

            构造器
            public FileInputStream(File file)   创建字节输入流管道与源文件接通
            public FileInputStream(String pathname) 创建字节输入流管道与源文件接通

            方法名称
            public int read()   每次读取一个字节返回，如果发现没有数据可读会返回-1
            public int read(byte[] buffer)
            每次用一个字节数组去读取数据，返回字节数组读取了多少个字节，如果发现没有数据可读会返回-1
     */
    public static void main(String[] args) throws IOException {
        InputStream is = new FileInputStream(("file-io-app\\src\\itheima01.txt"));

        //开始读取文件字节数据
        int b1 = is.read();
        System.out.println((char)b1);

        //使用循环改造上述代码
        int b;
        while((b=is.read())!=-1){
            System.out.print((char)b);
        }

        is.close();

        //一次读多个数据
        byte[] buffer = new byte[3];
        int len;
        while((len=is.read(buffer))!=-1){
            String rs = new String(buffer,0,len);
            System.out.print(rs);
        }
        is.close();

        //一次读取全部数据
        //方法1：定义长度和要读取文件等长的数组
        //方法2：Java官方为InputStream提供方法，可以直接把文件的全部字节读取到一个字节数组中返回
        //  public byte[] readAllByte() throwsIOException
        //  直接将当前字节输入流对应的文件对象的字节数据装到一个字节数组返回
        byte[] buffers = is.readAllBytes();
        System.out.println(new String(buffer));
    }
}
