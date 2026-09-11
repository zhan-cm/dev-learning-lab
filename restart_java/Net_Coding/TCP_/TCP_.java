package Net_Coding.TCP_;

public class TCP_ {
    /*
        特点：面向连接、可靠通信
        通信双方实现会采用“三次握手”方式建立可靠连接，实现端到端的通信；底层保证数据成功传给服务端
        java提供了一个java.net.Socket类来实现TCP通信
        -------------------------------------------------------------------

        TCP通信之-客户端开发
        客户端程序就是通过java.net包下的Socket类实现的
        构造器
        public Socket(String host,int port) 根据指定的服务器IP、端口号请求与服务器建立连接，连接通过。就获得了客户端socket

        方法
        public OutputStream getOutputStream()   获得字节输出流对象
        public InputStream getInputStream() 获得字节输入流对象
        ------------------------------------------------------------------

        TCP通信-服务端程序的开发
        服务端是通过java.net包下的ServerSocket类来实现的
        构造器
        public ServerSocket(int port)   为服务端程序注册端口
        方法
        public Socket accept()  阻塞等待客户端的连接请求，一旦与某个客户端成功连接，则返回服务端这边的Socket对象


     */
}
