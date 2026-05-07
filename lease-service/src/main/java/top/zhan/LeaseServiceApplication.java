package top.zhan;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;

@SpringBootApplication
@EnableFeignClients
public class LeaseServiceApplication {
    public static void main(String[] args) {
        SpringApplication.run(LeaseServiceApplication.class, args);
    }
}
