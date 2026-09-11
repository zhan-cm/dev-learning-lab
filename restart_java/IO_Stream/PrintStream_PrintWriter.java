package IO_Stream;

public class PrintStream_PrintWriter {
    //打印流
    //作用：打印流可以实现更方便、更高效的打印数据出去，能实现打印啥出去就是啥出去
    /*
        构造器
        public PrintStream(OutputStream/File/String)    打印流直接通向字节输出流/文件/文件路径
        public PrintStream(String filename,Charset charset) 可以指定写出去的字符编码
        public PrintStream(OutputStream out,boolean autoFlush)  可以指定实现自动刷新
        public PrintStream(OutputStream out,boolean autoFlush,String encoding)  可以指定实现自动刷新，并可指定字符的编码

        方法
        public void println(Xxx xx) 打印任意类型的数据出去
        public void write(int/byte[]/byte[]一部分) 可以支持写字节数据出去

        ==================================================================
        构造器
        public PrintWriter(OutputStream/Writer/File/String)    打印流直接通向字节输出流/文件/文件路径
        public PrintWriter(String filename,Charset charset) 可以指定写出去的字符编码
        public PrintWriter(OutputStream out/Writer,boolean autoFlush)  可以指定实现自动刷新
        public PrintWriter(OutputStream out,boolean autoFlush,String encoding)  可以指定实现自动刷新，并可指定字符的编码

        方法
        public void println(Xxx xx) 打印任意类型的数据出去
        public void write(int/byte[]/byte[]一部分) 可以支持写字符数据出去

        =================================================================
        PrintStream和PrintWriter的区别
            打印数据的功能上是一模一样的：都是使用方便，性能高效
            PrintStream继承自字节输出流OutputStream，因此支持写字节数据的方法
            PrintWriter继承自字符输出流Writer，因此支持写字符数据出去
     */
}
