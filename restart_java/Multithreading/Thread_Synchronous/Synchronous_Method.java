package Multithreading.Thread_Synchronous;

public class Synchronous_Method {
    /*
        同步方法：
            作用：把访问共享资源的核心方法给上锁，以此保证线程安全

            修饰符 synchronized 返回值类型 方法名称(形参列表){
                操作共享资源的代码
            }

            原理：每次只能一个线程进入，执行完毕以后自动解锁，其他线程才可以进来执行
     */
}
