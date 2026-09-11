package JDK8_add_new_Time;

import java.time.LocalDate;
import java.time.Period;

public class Period_ {
    //可以用于计算两个LocalDate对象 相差的年数、月数、天数
    /*
        方法：
            public static Period between(LocalDate start,LocalDate end) 传入两个日期对象，得到Period对象
            public int getYears()   计算隔几年，并返回
            public int getMonths()   计算隔几月，并返回
            public int getDays()   计算隔多少天，并返回
     */
    public static void main(String[] args) {
        LocalDate start = LocalDate.of(2029, 8, 10);
        LocalDate end = LocalDate.of(2029, 8, 15);

        //1.创建Period对象，封装两个日期对象
        Period p = Period.between(start, end);
        //后面就是调用方法了，这里不再写了
    }
}
