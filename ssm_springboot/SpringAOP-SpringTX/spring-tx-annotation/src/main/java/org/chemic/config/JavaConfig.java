package org.chemic.config;

import com.alibaba.druid.pool.DruidDataSource;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.*;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.datasource.DataSourceTransactionManager;
import org.springframework.transaction.TransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;
import org.springframework.transaction.support.TransactionTemplate;

import javax.sql.DataSource;

@Configuration
@ComponentScan("org.chemic")
@PropertySource("classpath:jdbc.properties")
//@EnableTransactionManagement //开启aspect注解的支持
//@EnableAspectJAutoProxy   //开启事务注解的支持
public class JavaConfig {

    @Value("${spring.diver}")
    private String driverClassName;
    @Value("${spring.url}")
    private String url;
    @Value("${spring.username}")
    private String username;
    @Value("${spring.password}")
    private String password;

    //druid连接池
    @Bean
    public DataSource dataSource() {
        DruidDataSource dataSource = new DruidDataSource();
        dataSource.setDriverClassName(driverClassName);
        dataSource.setUrl(url);
        dataSource.setUsername(username);
        dataSource.setPassword(password);
        return dataSource;
    }

    @Bean
    public JdbcTemplate jdbcTemplate(DataSource dataSource) {
        JdbcTemplate jdbcTemplate = new JdbcTemplate();
        jdbcTemplate.setDataSource(dataSource);
        return jdbcTemplate;
    }

    @Bean
    public TransactionManager transactionManager(DataSource dataSource) {
        //内部要进行事务的操作，基于连接池
        DataSourceTransactionManager transactionManager = new DataSourceTransactionManager();
        //需要连接池对象
        transactionManager.setDataSource(dataSource);
        return transactionManager;

    }
}
