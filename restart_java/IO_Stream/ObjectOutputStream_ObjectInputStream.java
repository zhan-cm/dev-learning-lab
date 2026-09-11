package IO_Stream;

public class ObjectOutputStream_ObjectInputStream {
    /*
        ObjectOutputStream对象字节输出流
            可以把Java对象进行序列化：把Java对象存入到文件中去

        构造器
        public ObjectOutputStream(OutputStream out) 创建对象字节输出流，包装基础的字节输出流

        方法
        public final void writeObject(Object o) throws IOException  把对象写出去

        !!!注意：对象如果需要序列化，必须实现序列化接口Serializable
     */
    /*
        ObjectInputStream对象字节输入流
            可以把Java对象进行反序列化：把存储在文件中的Java对象读入到内存中来

        构造器
        public ObjectInputStream(InputStream out) 创建对象字节输入流，包装基础的字节输入流

        方法
        public final void readObject() 把存储在文件中的Java对象读出来

        !!!transient某个成员变量将不参与序列化
     */
    /*
        如果要一次序列化多个对象？
            用一个Array List集合存储多个对象，然后直接对集合进行序列化即可
                注意：ArrayList集合已经实现了序列化接口
     */
}
