package Multithreading.Thread_Base;

public class Thread_ {
    public static void main(String[] args) {
        Thread t = new MyThread();
        t.start();
    }
    /*
        启动线程必须是调用start方法，不是调用run方法
        不要把主线程人物放在启动子线程之前
     */
}

