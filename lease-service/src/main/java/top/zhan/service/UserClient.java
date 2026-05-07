package top.zhan.service;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

// 这里的 "user-service" 就是你在 Nacos 中看到的服务名！
@FeignClient(name = "user-service")
public interface UserClient {

    // 这里的签名和 User-Service 里的 Controller 保持一致即可
    @GetMapping("/user/{id}")
    String getUserById(@PathVariable("id") Long id);
}