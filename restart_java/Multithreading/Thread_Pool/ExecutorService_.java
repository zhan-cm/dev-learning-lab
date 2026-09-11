package Multithreading.Thread_Pool;

public class ExecutorService_ {
    /*
        ExecutorService常用方法：
            void executor(Runnable command) 执行Runnable任务
            Future<T> submit(Callable<T> task)  执行Callable任务，返回未来任务对象，用于获取线程返回的结果
            void shutdown() 等全部任务执行完毕后，再关闭线程池！
            List<Runnable> shutdownNow()    立即关闭线程池，停止正在执行的任务，并返回队列中未执行的任务


        新任务拒绝策略：
            ThreadPoolExecutor.AbortPolicy  丢弃任务并抛出RejectedExecutionException异常，是默认的策略
            ThreadPoolExecutor.DiscardPolicy    丢弃任务，但不抛出异常，这是不推荐的做法
            ThreadPoolExecutor.DiscardOldestPolicy  抛弃队列中等待最久的任务，然后把当前任务加入队列中
            ThreadPoolExecutor.CallerRunsPolicy 由主线程负责调用任务的run()方法从而绕过线程池直接执行


     */
}
