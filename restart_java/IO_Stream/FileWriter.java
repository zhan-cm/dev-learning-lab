package IO_Stream;

public class FileWriter {
    /*
        FileWriter文件字符输出流
            以内存为基准，把内存中的数据以字符形式写出到文件中去

        构造器
        public FileWriter(File file)    创建字节输出流管道与源文件对象接通
        public FileWriter(String filepath)  创建字节输出流管道与源文件对象接通
        public FileWriter(File file,boolean append) 创建字节输出流管道与源文件对象接通，可追加数据
        public FileWriter(String filepath,boolean append)   创建字节输出流管道与源文件对象接通，可追加数据

        方法
        void write(int c)   写一个字符
        void write(String str)  写一个字符串
        void write(String str,int off,int len)  写一个字符串的一部分
        void write(char[] cbuf) 写入一个字符数组
        void write(char[] cbuf,int off,int len) 写入字符数组的一部分

        字符输出流使用时的注意事项：
            字符输出流写出数据后，必须刷新流，或者关闭流，写出去的数据才能生效
            public void flush() throws IOException 刷新流，就是将内存中缓存的数据立即写到文件中去生效
            public void close() throws IOException  关闭流的操作，包含了刷新！
     */
}
