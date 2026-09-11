package Multithreading.Thread_Base;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

public class Callable_ {
    /*
        利用Callable接口、FutureTask类实现
            创建任务对象
                定义一个类实现Callable接口，重写call方法，封装要做的事情，和要返回的数据
                把Callable类型的对象封装成FutureTask（线程任务对象）
            把线程任务对象交给Thread对象
            调用Thread对象的start方法启动线程
            线程执行完毕后，通过FutureTask对象的get方法去获取线程任务执行的结果
     */
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        Callable<String> call = new MyCallable(100);

        FutureTask<String> f1 = new FutureTask<>(call);

        Thread thread = new Thread( f1);

        thread.start();
        //
        String rs = f1.get();
        System.out.println(rs);
    }
}
