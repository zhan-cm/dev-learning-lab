package Net_Coding.UDP;

public class UDP_ {
    /*
        特点：无连接，不可靠通信
        不事先建立连接；发送端每次把要发送的数据（限制在64KB内）、接收端IP、等信息封装成一个数据包，发出去就不管了
        Java提供了一个java.net.DatagramSocket类来实现UDP通信

        DatagramSocket:用于创建客户端、服务端
        构造器
        public DatagramSocket() 创建客户端的Socket对象，系统会随机分配一个端口号
        public DatagramSocket(int port) 创建服务器的Socket对象，并指定端口号

        方法
        public void send(DatagramPacket dp) 发送数据包
        public void receive(DatagramPacket p)   使用数据包接收数据
        -----------------------------------------------------------
        DatagramPacket:创建数据包
        构造器
        public DatagramPacket(byte[] buf.int length,InetAddress address,int port)   创建发出去的数据包对象
        public DatagramPacket(byte[] buf,int length)    创建用来接收数据的数据包

        方法
        public int getLength()  获取数据包，实际接收到的字节个数
     */
}
