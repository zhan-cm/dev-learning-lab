package JDK8_add_new_Time;

public class Instant {
    //时间线上的某个时刻/时间戳
    //通过获取Instant的对象可以拿到此刻的时间，该时间由两部分组成：从1970-01-01 00：00：00
    //开始走到此刻的总秒数+不够一秒的纳秒数
    /*
        常见方法：
        Instant now()   获取当前时间的Instant对象（标准时间）
        long getEpochSecond()   获取从1970-01-01T00:00:00开始的记录的秒数
        int getNano()   从时间线开始，获取从第二个开始的纳秒数
        plusMillis plusSeconds plusNano     判断系列的方法
        minusMillis minusSeconds minusNanos 减少时间系列的方法
        equals isBefore isAfter 增加时间系列的方法
     */
}
