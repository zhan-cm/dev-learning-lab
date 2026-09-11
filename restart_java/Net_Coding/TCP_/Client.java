package Net_Coding.TCP_;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws Exception {
        //创建Socket对象，并同时请求与服务器程序的连接
        Socket socket = new Socket("127.0.0.1",8888);
        Scanner sc= new Scanner(System.in);
        //从Socket通信管道中的得到一个字节输出流，用来发数据给服务器程序
        OutputStream os = socket.getOutputStream();
        //把低级的字节输出流包装成数据输出流
        DataOutputStream dataOutputStream = new DataOutputStream(os);
        //开始写数出去
        while (true) {
            System.out.println("请说：");
            String s = sc.nextLine();
            if("exit".equals(s)){
                dataOutputStream.close();
                System.out.println("客户端已关闭");
                socket.close();
                break;
            }
            dataOutputStream.writeUTF(s);
        }


    }
}
