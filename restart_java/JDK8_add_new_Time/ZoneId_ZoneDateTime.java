package JDK8_add_new_Time;

import java.time.ZoneId;
import java.time.ZonedDateTime;

public class ZoneId_ZoneDateTime {
    /*
        中国标准时间：世界标准时间+8小时
        ZoneId:代表时区Id

        ZoneId:
        public static ZoneId systemDefault();   获取系统默认的时区

        public static Set<String> getAvailableZoneIds();    获取Java支持的所有时区Id

        public static ZoneId of(String zoneId); 把某个时区id封装成ZoneId对象

        ----------------------------------------------------

        ZoneDateTime:
        public static ZoneDateTime now(ZoneId zone);    获取某个时区的ZoneDateTime对象

        public static ZoneDateTime now();   获取系统默认时区的ZoneDateTime对象
     */
    public static void main(String[] args) {
        ZoneId zoneId = ZoneId.systemDefault();
        System.out.println(zoneId.getId());

        System.out.println(ZoneId.getAvailableZoneIds());

        ZoneId zoneId1 = ZoneId.of("America/New_York");

        ZonedDateTime zonedDateTime = ZonedDateTime.now(zoneId1);
        System.out.println(zonedDateTime);
    }

}
