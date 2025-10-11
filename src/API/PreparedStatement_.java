package API;

public class PreparedStatement_ {
    /*
        PreparedStatement作用：
            1.预编译SQL语句并执行：预防SQL注入问题
        SQL注入
            SQL注入是通过操作输入来修改事先定义好的SQL语句，用来达到执行代码对服务器进行攻击的方法
            eg:select * from tb_user where username = 'sdjai' and password = '  'or '1'='1  '

        1.获取PreparedStatement对象
            //SQL语句中的参数值，使用？占位符替代
            String sql = "select * from user where username = ? and password = ?";

            //通过Connection对象获取，并传入对应的sql语句
            PreparedStatement pstmt = conn,prepareStatement(sql);
        2.设置参数值
            PrepareStatement对象：setXxx(参数1，参数2); 给？赋值
                Xxx:数据类型; 如setInt(参数1，参数2)
                参数：
                    参数1： ？的位置编号，从1开始
                    参数2： ？的值
        3.执行SQL
            executeUpdate();/executeQuery();    不需要再传递sql

        -----------------------------------------------------------------------
        PreparedStatement原理
            PreparedStatement好处：
                1.预编译SQL，性能更高
                2.防止SQL注入：将敏感字符进行转义

            1.PreparedStatement预编译功能开启：useServerPreparedStmts=true

            2.配置MYSQL执行日志（重启mysql服务生效）
            log-output=FILE
            general-log=1
            general_log_file="D:\mysql.log"
            slow-query-log=1
            slow_query_log_file="D:\mysql_slow.log"
            long_query_time=2


            PreparedStatement原理：
                1.在获取PreparedStatement对象时，将sql语句发送给mysql服务器进行检查，编译（耗时）
                2.执行时就不要再进行这些步骤，速度快
                3.如果sql模板一样，则只需要进行一次检查，编译

     */
}
