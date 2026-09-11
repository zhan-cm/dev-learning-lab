package Multithreading.Thread_Pool;

public class Executors_ {
    /*
        Executors:是一个线程池的工具类，提供了很多静态方法用于返回不同特点的线程池对象

        public static ExecutorService newFixedThreadPool(int nThreads)
        创建固定线程数量的线程池，如果某个线程因为执行异常而结束，那么线程池会补充一个新线程替代它

        public static ExecutorService newSingleThreadExecutor()
        创建只有一个线程的线程池对象，如果该线程出现异常而结束，那么线程会补充一个新线程

        public static ExecutorService newCachedThreadPool()
        线程数量随着任务增加而增加，如果线程任务执行完毕且空闲了60s则会回收掉

        public static ScheduledExecutorService newScheduledThreadPool(int corePoolSize)
        创建一个线程池，可以实现在给定的延迟后运行任务，或者定期执行任务


        注意：这些方法的底层，都是提供线程池的实现类ThreadPoolExecutor创建的线程池对象

        计算密集型任务：核心线程数量=CPU线程数+1
        IO密集型任务：CPU线程数*2
     */
}
