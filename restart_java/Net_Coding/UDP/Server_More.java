package Net_Coding.UDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class Server_More {
    public static void main(String[] args) throws Exception {
        System.out.println("=======服务端启动========");
        //创建一个服务端对象
        DatagramSocket socket = new DatagramSocket(6666);

        //创建一个数据包对象，用于接收数据的
        byte[] buffer = new byte[1024*64];
        DatagramPacket packet = new DatagramPacket(buffer,buffer.length);

        while (true) {
            //正式使用数据包接收客户端数据
            socket.receive(packet);

            //从字节数据中，把接收到的数据直接打印出来
            int len = packet.getLength();
            String s = new String(buffer,0,len);
            System.out.println(s);

            System.out.println(packet.getAddress().getHostAddress());
            System.out.println(packet.getPort());

            //socket.close();
        }
    }
}
