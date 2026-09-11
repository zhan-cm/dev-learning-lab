package Net_Coding.UDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class Client_More {
    public static void main(String[] args) throws Exception {
        //创建客户端对象
        DatagramSocket socket = new DatagramSocket();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("请说：");

            String message = sc.nextLine();
            byte[] bytes = message.getBytes();

            if("exit".equals(message)){
                System.out.println("退出客户端成功");
                socket.close();
                break;
            }


            //创建数据包对象封装要发出去的数据
            DatagramPacket packet = new DatagramPacket(bytes,bytes.length
                    , InetAddress.getLocalHost(),6666);

            //开始正式发送这个数据包的数据出去了
            socket.send(packet);
        }

        //System.out.println("客户端数据发送完毕~~~");
        //socket.close();
    }
}
