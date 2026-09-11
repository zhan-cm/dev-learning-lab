package top.zhan.service.controller;

import io.seata.spring.annotation.GlobalTransactional;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import top.zhan.service.UserClient;

@RestController
@RequestMapping("/lease")
@RefreshScope  // 【极其关键】有了这个注解，Nacos 里的值改了，这里的变量才会跟着变
public class LeaseController {

    // 使用 @Value 读取我们刚才在 Nacos 里写的参数
    @Value("${shangting.lease.discount}")
    private Double discount;

    @Value("${shangting.lease.memo}")
    private String memo;

    @GetMapping("/config-test")
    public String testConfig() {
        return "当前首月租金折扣为: " + discount + " | 留言: " + memo;
    }
    @GetMapping("/view")
    public String viewLease() {
        return "正在查看租赁详情，数据库查询成功！";
    }

    @Autowired
    private UserClient userClient; // 之前配好的 OpenFeign

    //@Autowired
    //private LeaseOrderService leaseOrderService; // 假设这是你的本地数据库业务

    // 【魔法就在这里】加上这个注解，开启全局分布式事务！
    // name 属性随便起，主要是为了在日志里好认
    // rollbackFor = Exception.class 表示遇到任何异常都回滚
    //@GlobalTransactional(name = "create-lease-tx", rollbackFor = Exception.class)
    //@GetMapping("/createOrder")
    //public String createLeaseOrder(Long userId) {

        // 1. 本地数据库操作：插入一条租赁合同记录 (属于本地事务)
        //leaseOrderService.createContract(userId);

        // 2. 远程调用：通过 Feign 告诉 User-Service 修改用户状态 (属于远程事务)
        //userClient.updateUserStatus(userId, "已租赁");

        // 3. 模拟一个巨大的灾难：突然抛出异常！
        // 如果不加 @GlobalTransactional，第1步的合同已经存进数据库了，无法挽回。
        // 但加了之后，Seata 会拦截这个异常，并立刻通知 lease 和 user 的数据库，把数据全撤回来！
        //int i = 10 / 0; // 故意制造除以0的异常

        //return "租赁订单创建成功！";
    //}
}