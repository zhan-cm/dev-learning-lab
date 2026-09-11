package Net_Coding.TCP_;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws Exception {
        //创建ServerSocket对象，同时为服务器注册端口
        ServerSocket serverSocket = new ServerSocket(8888);
        System.out.println("======服务端已启动======");
        //使用serverSocket对象，调用accept方法，等待客户端连接请求
        while (true) {
            Socket socket = serverSocket.accept();
            new ServerReaderThread(socket).start();
        }

        //dataInputStream.close();
        //serverSocket.close();
    }
}
