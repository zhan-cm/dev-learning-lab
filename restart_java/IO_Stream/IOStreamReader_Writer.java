package IO_Stream;

public class IOStreamReader_Writer {
    /*
        InputStreamReader字符输入转换流
        解决不同编码时，字符流读取文本内容乱码的问题
        解决思路：先获取文件的原始字节流，再将其按真实的字符集编码转成字符输入流，这样字符输入流中的字符就部乱码了

        构造器
        public InputStreamReader(InputStream is)    把原始的字节输入流，按照代码默认编码转成字符输入流
        public InputStreamReader(InputStream is,String charset)    把原始的字节输入流，按照指定字符集编码转成字符输入流
     */
    /*
        OutputStreamWriter字符输出转换流
        作用：可以控制写出去的字符使用什么字符集编码
        解决思路：获取字节输出流，再按照指定的字符集编码将其转换成字符输出流，以后写出去的字符就会用该字符集编码了

        构造器
        public OutputStreamReader(OutputStream is)    把原始的字节输出流，按照代码默认编码转成字符输出流
        public OutputStreamReader(OutputStream is,String charset)    把原始的字节输出流，按照指定字符集编码转成字符输出流
     */
}
