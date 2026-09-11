package Multithreading.Thread_Security;

public class ThreadTest {
    public static void main(String[] args) {
        Account acc = new Account(1000000,"ICBC-110");

        new DrawThread(acc,"小明").start();

        new DrawThread(acc,"小红").start();
    }
}
