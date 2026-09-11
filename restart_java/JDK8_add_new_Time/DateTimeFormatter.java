package JDK8_add_new_Time;

import java.time.LocalDateTime;

public class DateTimeFormatter {
    //格式化器，用于时间格式化、解析

    /*
        常见方法：
        DateTimeFormatter ofPattern(时间格式)   获取格式化器对象
        String format(时间对象)     格式化时间
     */

    public static void main(String[] args) {
        java.time.format.DateTimeFormatter formatter = java.time.format.DateTimeFormatter.ofPattern("yyyy年MM月dd日 HH:mm:ss");

        LocalDateTime now = LocalDateTime.now();
        System.out.println(now);

        String s = formatter.format(now);
        System.out.println(s);

    }
    /*
        LocalDateTime提供的格式化、解析时间的方法
        public String format(DateTimeFormatter formatter) 格式化时间
        public static LocalDateTime parse(charSequence text,DateTimeFormatter formatter) 解析时间

     */
}
