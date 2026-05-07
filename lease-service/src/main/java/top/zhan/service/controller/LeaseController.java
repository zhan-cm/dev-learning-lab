package top.zhan.service.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import top.zhan.service.UserClient;

@RestController
@RequestMapping("/lease")
public class LeaseController {

    @Autowired
    private UserClient userClient; // 直接注入刚才写的接口

    @GetMapping("/create")
    public String createLease(Long userId) {
        // 见证奇迹：我们没有写任何 HTTP 请求代码，也没有写死 127.0.0.1:8081
        String userInfo = userClient.getUserById(userId);

        return "租赁订单创建成功！对应的租客信息为：" + userInfo;
    }
}
