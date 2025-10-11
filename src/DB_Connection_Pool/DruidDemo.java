package DB_Connection_Pool;

import com.alibaba.druid.pool.DruidDataSource;
import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.sql.Connection;
import java.util.Properties;

public class DruidDemo {
    /*
        数据库连接池简介
            ·数据库连接池是个容器，负责分配，管理数据库连接Connection
            ·它允许应用程序重复使用一个现有的数据库连接，而不是再重新建立一个
            ·释放空闲时间超过最大空闲时间的数据库连接来避免因为没有释放数据库连接而引起的数据库连接遗漏
            ·好处：
                ·资源重用
                ·提升系统响应速度
                ·避免数据库连接遗漏
        ------------------------------------------------------------------
        数据库连接池实现
            ·标准接口：DataSource
                ·官方（SUN）提供的数据库连接池标准接口，由第三方组织实现此接口
                ·功能：获取连接
                Connection getConnection()
            ·常见的数据库连接池
                ·DBCP
                ·C3P0
                ·Druid
            ·Druid(德鲁伊)
                ·Druid连接池时阿里巴巴开源的数据库连接池项目
                ·功能强大、性能优秀，是Java语言最好的数据库连接池之一
     */
    public static void main(String[] args) throws Exception {
        //加载配置文件
        Properties prop = new Properties();
        prop.load(new FileInputStream("src/DB_Connection_Pool/druid.properties"));

        //获取连接池对象
        DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);

        //获取对应的数据库连接
        Connection connection = dataSource.getConnection();

        System.out.println(connection);
        //System.out.println(System.getProperty("user.dir"));
    }
}
