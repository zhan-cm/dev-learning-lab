package Net_Coding.TCP_;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class ServerReaderThread extends Thread {
    private Socket socket;
    public ServerReaderThread(Socket socket){
        this.socket=socket;
    }
    @Override
    public void run() {
        super.run();
        try {
            InputStream is = socket.getInputStream();
            DataInputStream dataInputStream = new DataInputStream(is);
            while(true){
                try {
                    String s = dataInputStream.readUTF();
                    System.out.println(s);
                } catch (IOException e) {
                    System.out.println("有人下线了"+socket.getRemoteSocketAddress());
                    dataInputStream.close();
                    socket.close();
                    break;
                }
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
