package top.zhan.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/user")
public class UserController {

    @GetMapping("{id}")
    public String getUserById(@PathVariable Long id){
        //模拟数据库查询
        return "查询成功：用户ID=" + id + ", 姓名=张三";
    }
}
