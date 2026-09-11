package Multithreading.Thread_Base;

public class Runnable_ {
    public static void main(String[] args) {
        Runnable target = new MyRunnable();

        new Thread(target).start();

        for (int i = 0; i <100 ; i++) {
            System.out.println("主线程输出===>"+i);
        }
    }
    /*
        实现Runnable接口
            定义一个线程任务类MyRunnable实现Runnable接口，重写run()方法
            创建MyRunnable任务对象
            把MyRunnable任务对象交给Thread处理
                public Thread(Runnable target)  封装成Runnable对象成为线程对象
            调用线程对象的start()方法启动线程
     */
}
