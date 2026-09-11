package Multithreading.Thread_Synchronous;

public class Synchronous_Code_Block {
    /*
        同步代码块
            作用：把访问共享资源的核心代码给上锁，以此保证线程安全
            synchronized(同步锁){
                访问共享资源的核心代码
            }

        原理：每次只允许一个线程加锁后进入，执行完毕后自动解锁，其他线程才可以进来执行

        同步锁的注意事项：
            对于当前同时执行的线程来说，同步锁必须是同一把（同一个对象），否则会出bug

        锁对象的使用规范：
            建议使用共享资源作为锁对象，对于实例方法建议使用this作为锁对象
            对于静态方法建议使用字节码（类名.class）对象作为锁对象
     */
}
