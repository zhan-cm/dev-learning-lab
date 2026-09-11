import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.Connection;

public class JDBCDemo {
    public static void main(String[] args) throws Exception {
        //注册驱动
        Class.forName("com.mysql.jdbc.Driver");

        //获取连接
        String url ="jdbc:mysql://127.0.0.1:3306/test?useSSL=false";
        String username ="root";
        String password ="123456";
        Connection coon = DriverManager.getConnection(url,username,password);

        //定义sql
        String sql = "select * from user";

        //获取执行sql的对象Statement
        Statement statement = coon.createStatement();

        //执行sql
        ResultSet resultSet = statement.executeQuery(sql);//受影响的行数

        //处理结果
        while (resultSet.next()) {
            String name = resultSet.getString("name");
            int id = resultSet.getInt("id");
            System.out.println("ID: " + id + ", Name: " + name);
        }

        //释放资源
        statement.close();
        coon.close();
    }
}
