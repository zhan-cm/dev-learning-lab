package Multithreading.Thread_Pool;

import java.util.concurrent.*;

public class Thread_Pools {
    /*
        线程池：一个可以复用线程的技术

        不使用线程池的问题
            用户每次发起一个请求，后台就需要创建一个新线程来处理，下次新任务来了肯定又要创建新线程处理，
            而创建新线程的开销很大，并且请求过多时，肯定会产生大量线程出来，会严重影响系统性能

        如何获得线程池对象
            方式一：
                使用ExecutorService的实现类ThreadPollExecutor自创建一个线程对象
            方式二：
                使用Executors（线程池的工具类）调用方法返回不同特点的线程池对象
     */
    /*
        ThreadPoolExecutor构造器
            public ThreadPoolExecutor(int corePoolSize,int maximumPoolSize,long keepAliveTime,
                            TimeUnit unit,BlockingQueue<Runnable> workQueue,
                            ThreadFactory threadFactory,RejectedExecutionHandler handler)

            参数一：corePoolSize：指定线程池的核心线程数量
            参数二：maximumPoolSize：指定线程池的最大线程数量
            参数三：keepAliveTime：指定临时线程的存活时间
            参数四：unit：指定临时线程存活的时间单位（秒、分、时、天）
            参数五：workQueue：指定线程池的任务队列
            参数六：threadFactory：指定线程池的线程工厂
            参数七：handler：指定线程池的任务拒绝策略（线程都在忙，任务队列也满了的时候，新任务来了该怎么处理）
     */
    public static void main(String[] args) {
        ExecutorService pool = new ThreadPoolExecutor(3,5,8, TimeUnit.SECONDS
        ,new ArrayBlockingQueue<>(4), Executors.defaultThreadFactory()
        ,new ThreadPoolExecutor.AbortPolicy());
    }
    /*
        线程池的注意事项：
            临时线程什么时候创建？
                新任务提交时返现核心线程都在忙，任务队列也满了，并且还可以创建临时线程
            什么时候会开始拒绝新任务？
                核心线程和临时线程都在忙，任务队列也满了，新任务来的时候就会开始拒绝任务

     */
}
