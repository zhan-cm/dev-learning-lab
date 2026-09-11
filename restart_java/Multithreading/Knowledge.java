package Multithreading;

public class Knowledge {
    /*
        进程：
            正在运行的程序就是一个独立的进程
            线程属于进程的，一个进程中可以同时运行多个线程
            进程中的多个线程其实是并发和并行执行的

        并发：
            进程中的线程是由CPU负责调度执行的，但CPU能同时处理线程的数量有限，为了保证全部
            线程都能往前执行，CPU会轮询为系统的每个线程服务，由于CPU切换的速度很快，给我们
            感觉这些线程在同时进行，就是并发

        并行：
            在同一时刻上，同时有多个线程在被CPU调度执行
     */
    /*
        线程的生命周期
            也就是线程从生到死的过程，经历各种状态及状态转换

         线程的6中状态
         NEW(新建)    线程刚被创建，但是并未启动
         Runnable(可运行)  线程已经调用了start()，等待CPU调度
         Blocked(锁阻塞)   线程在执行的时候未竞争到锁对象，则该线程进入Blocked状态
         Waiting(无限等待)  一个线程进入Waiting状态，另一个线程调用notify或者notifyAll方法才能唤醒
         Timed Waiting(计时等待)    同waiting状态，有几个方法(sleep,wait)有超时参数，调用他们将进入Timed Waiting状态
         Teminated(被终止) 因为run方法正常退出而死亡，或者因为没有捕获的异常终止了run方法而死亡
     */
}
