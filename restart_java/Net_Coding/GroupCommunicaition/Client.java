package Net_Coding.GroupCommunicaition;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Socket socket = new Socket("172.0.0.1",9999);

        DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());

        while (true){
            System.out.println("请说：");
            String s = sc.nextLine();
            if("exit".equals(s)){
                System.out.println("欢迎下次使用");
                dataOutputStream.close();
                socket.close();
                break;
            }
            dataOutputStream.writeUTF(s);
            dataOutputStream.flush();
        }

    }
}
