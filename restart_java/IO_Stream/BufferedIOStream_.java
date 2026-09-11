package IO_Stream;

import java.io.*;

public class BufferedIOStream_ {
    /*
        提高字节流读写数据的性能
        原理：字节缓冲输入流自带了8KB缓冲池，字节缓冲输出流也自带了8KB缓冲池

        构造器
        public BufferedInputStream  把低级的字节输入流包装成一个高级的缓冲字节输入流，从而提高读数据的性能
        public BufferedOutputStream  把低级的字节输出流包装成一个高级的缓冲字节输出流，从而提高写数据的性能
     */
    public static void main(String[] args) {
        try (
                InputStream is = new FileInputStream("D:/resource/meinv.png");
                OutputStream os = new FileOutputStream("C:/data/meinv.png");

                InputStream bis = new BufferedInputStream(is);
                OutputStream bos = new BufferedOutputStream(os);
        ){
            //创建一个字节数组，负责转移字节数据
            byte[] bytes = new byte[1024];
            //从字节输入流中读取字节数据，写出去到字节输出流中，读多少写出去多少
            int len;
            while((len = bis.read())!=-1){
                bos.write(bytes,0,len);
            }
            System.out.println("复制完成！！！");
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
