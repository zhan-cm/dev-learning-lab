package JDK8_add_new_Time;

public class LocalDate_LocalTime_LocalDateTime {
    /*
        三者共同获取对象的方案
        public static Xxxx now() 获取系统当前时间对应的对象
        eg：
            LocalDate ld = LocalDate.now();

        public static Xxxx of() 获取指定时间的对象
        eg：
            LocalDate ld = LocalDate.of(2009,11,21);
        ------------------------------------------
         LocalDate:
            int getYear()   获取年份
            int getMonthValue() 获取月份
            int getDayOfMonth() 获取日
            int getDayOfYear()  一年中的第几天
            DayOfWeek getDayOfWeek()
            int getDayOfWeek().getValue()   星期几

            withYear,withMonth,withDayOfMonth,withDayOfYear
            直接修改某个信息，返回新日期对象

            plusYears,plusMonths,plusDays,plusWeeks
            把某个信息加多少，返回新日期对象

            minusYears,minusMonths,minusDays,minusWeeks
            把某个信息减多少，返回新日期对象

            equals isBefore isAfter
            判断两个日期对象是否相等，在前还是在后

        -------------------------------------------
        LocalTime:
            int getHour()   获取小时
            int getMinute() 获取分
            int getSecond() 获取秒
            int getNano()   获取纳秒

            withHour,withMinute,withSecond,withNano
            修改时间，返回新时间对象

            plusHours,plusMinutes,plusSeconds,plusNanos
            把某个信息加多少，返回新日期对象

            minusHours,minusMinutes,minusSeconds,minusNanos
            把某个信息减多少，返回新时间对象

            equals isBefore isAfter
            判断两个时间对象是否相等，在前还是在后

        --------------------------------------------------
        LocalDateTime:
            getYear,getMonthValue,getDayOfMonth,getDayOfYear
            getDayOfWeek,getHour,getMinute,getSecond,getNano
            获取年月日时分秒纳秒

            withYear,withMonth,withDayOfMonth,withDayOfYear
            withHour,withMinute,withSecond,withNano
            修改某个信息，返回新日期对象

            plusYears,plusMonths,plusDays,plusWeeks
            plusHours,plusMinutes,plusSeconds,plusNanos
            把某个信息加多少，返回新日期对象

            minusYears,minusMonths,minusDays,minusWeeks
            minusHours,minusMinutes,minusSeconds,minusNanos
            把某个信息减多少，返回新时间对象

            equals isBefore isAfter
            判断两个时间对象是否相等，在前还是在后
     */
}
