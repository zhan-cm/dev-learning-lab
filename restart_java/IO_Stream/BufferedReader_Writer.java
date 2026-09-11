package IO_Stream;

import java.io.*;

public class BufferedReader_Writer {
    /*
        BufferedReader字符缓冲输入流
        作用：自带8K的字符缓冲池，可以提高字符输入流读取字符数据的性能

        构造器
        public BufferedReader(Reader r) 把低级的字符输入流包装成字符缓冲输入流管道，从而提高字符输入流读字符数据的性能

        字符缓冲输入流新增的功能：按照行读取字符
        public String readLine()    读取一行数据返回，如果没有数据可读了，会返回null
     */
    public static void main(String[] args) {

    }
    /*
        BufferedWriter字符缓冲输出流
        作用：自带8K的字符缓冲池，可以提高字符输出流读取字符数据的性能

        构造器
        public BufferedWriter(Writer r) 把低级的字符输出流包装成字符缓冲输出流管道，从而提高字符输出流读字符数据的性能

        字符缓冲输出流新增的功能：换行
        public void newLine()   换行
     */
}
