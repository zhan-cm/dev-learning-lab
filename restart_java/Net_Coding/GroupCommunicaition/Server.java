package Net_Coding.GroupCommunicaition;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server {
    public static List<Socket> onLineSockets = new ArrayList<>();
    public static void main(String[] args) throws Exception {
        System.out.println("======服务器已开启=======");
        ServerSocket socket = new ServerSocket(8888);
    }
}
