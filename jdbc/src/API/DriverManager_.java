package API;

public class DriverManager_ {
    /*
        DriverManager（驱动管理类）作用：
            1.注册驱动
                Class.forName("com.mysql.jdbc.Diver");
                查看Diver源码
                static{
                    try{
                        DiverManager.registerDiver(new Diver());
                    } catch (SQLException var1) {
                        throws new RuntimeException("Can't register diver!");
                    }
                }
            2.获取数据库连接
                static Connection   getConnection(String url,String user,String password)
                参数：
                    1.url：连接路径
                        语法：jdbc:mysql://ip地址(域名):端口号/数据库名称？参数键值对1&参数键值对2...
                        示例：jdbc:mysql://127.0.0.1:3306/db1
                        细节：
                            如果连接的是本机MySQL服务器，并且MySQL服务默认端口为3306，则url可以简写成：jdbc:mysql:///数据库名称？参数键值对
                            配置useSSL=false 参数，禁用安全连接方法，解决警告提示
                    2.user：用户名
                    3.password：密码
     */
}
