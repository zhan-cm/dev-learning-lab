package IO_Stream;

public class DataInputStream_DataOutputStream {
    /*
        DataOutputStream数据输出流
            允许把数据和其类型一并写出去

        构造器
        public DataOutputStream(OutputStream out)   创建新数据输出流包装基础的字节输出流

        方法
        public final void writeByte(int v) throws IOException 将byte类型的数据写入基础的字节输出流
        public final void writeInt(int v) throws IOException  将int类型的数据写入基础的字节输出流
        public final void writeDouble(Double v) throws IOException  将double类型的数据写入基础的字节输出流
        public final void writeUTF(String str) throws IOException   将字符串数据以UTF-8编码成字节写入基础的字节输出流
        public void write(int/byte[]/byte[]一部分) 支持写字节数据出去
     */
    /*
        DataInputStream数据输如流
            用于读取数据输出流写出去的数据

        构造器
        public DataInputStream(InputStream out)   创建新数据输入流包装基础的字节输入流

        方法
        public final void readByte(int v) throws IOException 读取字节数据返回
        public final int readInt(int v) throws IOException  读取int类型数据返回
        public final double readDouble(Double v) throws IOException  读取double类型数据返回
        public final String readUTF(String str) throws IOException   读取字符串数据(UTF-8)返回
        public void readInt()/read(byte[]) 支持读字节数据出去
     */
}
