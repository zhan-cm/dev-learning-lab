package IO_Stream;

import java.io.*;

public class Release_Resources {
    /*
        try-catch-finally
        finally:无论try中程序是否正常执行，还是出现异常，最后都一定会执行finally区，除非JVM终止
        作用：一般用于在程序执行完成后进行资源的释放操作（专业做法）
     */
    /*
        try-with-resource
        try(定义资源1,定义资源2;...){
            可能出现异常的代码;
        }catch(){
            异常处理代码;
        }
        该资源使用完毕后，会自动调用其close()方法，完成对资源的释放
     */
    public static void main(String[] args) {
        InputStream is = null;
        OutputStream os = null;
        try {
            is = new FileInputStream("D:/resource/meinv.png");
            os = new FileOutputStream("C:/data/meinv.png");
            //创建一个字节数组，负责转移字节数据
            byte[] bytes = new byte[1024];
            //从字节输入流中读取字节数据，写出去到字节输出流中，读多少写出去多少
            int len;
            while((len = is.read())!=-1){
                os.write(bytes,0,len);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            try {
                if(os!=null) os.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
            try {
                if(is!=null)is.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        //============================
        try (
                InputStream is1 = new FileInputStream("D:/resource/meinv.png");
                OutputStream os1 = new FileOutputStream("C:/data/meinv.png");

                //注意：这里只能放置资源对象（流对象）
                //int age = 21;错
                //什么是资源？资源都是会实现AutoCloseable接口
                ){
            //创建一个字节数组，负责转移字节数据
            byte[] bytes = new byte[1024];
            //从字节输入流中读取字节数据，写出去到字节输出流中，读多少写出去多少
            int len;
            while((len = is.read())!=-1){
                os.write(bytes,0,len);
            }
            System.out.println("复制完成！！！");
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
