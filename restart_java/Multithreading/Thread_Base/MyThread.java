package Multithreading.Thread_Base;

public class MyThread extends Thread{
    public void run(){
        for (int i = 0; i < 5; i++) {
            System.out.println("子"+i);
        }
    }
}
