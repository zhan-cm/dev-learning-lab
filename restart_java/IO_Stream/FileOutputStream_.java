package IO_Stream;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class FileOutputStream_ {
    /*
        FileOutputStream文件字节输出流
            以内存为基准，把内存中的数据以字节的形式写出到文件中去

        构造器
        public FileOutputStream(File file)
        public FileOutputStream（String filepath)
        public FileOutputStream(File file,boolean append)
        public FileOutputStream(String filepath,boolean append)

        方法
        public void write(int a)    写一个字节出去
        public void write(byte[] buffer)    写一个字节数组出去
        public void write(byte[] buffer,int pos,int len)    写一个字节数组的一部分出去
        public void close() throws IOException  关闭流
     */
    public static void main(String[] args) throws IOException {
        OutputStream os = new FileOutputStream("file-io-app/src/itheima.txt");

        os.write(97);//97就是一个字节，代表a
        os.write('b');//'b'也是一个字节

        os.close();
    }
}
