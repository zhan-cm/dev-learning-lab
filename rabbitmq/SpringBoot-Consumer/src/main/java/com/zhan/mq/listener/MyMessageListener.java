package com.zhan.mq.listener;

import lombok.extern.slf4j.Slf4j;
import com.rabbitmq.client.Channel;
import org.springframework.amqp.core.Message;
import org.springframework.amqp.rabbit.annotation.Exchange;
import org.springframework.amqp.rabbit.annotation.Queue;
import org.springframework.amqp.rabbit.annotation.QueueBinding;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.stereotype.Component;

@Component
@Slf4j
public class MyMessageListener {
  
    public static final String EXCHANGE_DIRECT = "exchange.direct.order";  
    public static final String ROUTING_KEY = "order";  
    public static final String QUEUE_NAME  = "queue.order";  
  
    @RabbitListener(bindings = @QueueBinding(
            value = @Queue(value = QUEUE_NAME, durable = "true"),
            exchange = @Exchange(value = EXCHANGE_DIRECT),
            key = {ROUTING_KEY}
    ))
    /**
     * 核心作用： SpringAMQP 自动完成【交换机 ↔ 队列 ↔ 路由键】绑定，当前方法作为消费者监听指定队列，队列收到消息自动执行该方法。
     * 1. 外层 @RabbitListener
     *  标注在消费方法上，声明这是 RabbitMQ 消费者。
     *  bindings = @QueueBinding：自动绑定配置，项目启动时：不存在交换机 / 队列则自动创建 + 自动绑定队列到交换机。
     *  对比：不在注解配置 bindings 就需要手动用代码创建交换机、队列、绑定关系。
     * 2. @QueueBinding：绑定对象（队列 + 交换机 + 路由键三合一）
     *  是绑定中间载体，负责把队列、交换机、路由规则绑定在一起，三个属性：
     *  value = @Queue：绑定的目标队列
     *  exchange = @Exchange：绑定的目标交换机
     *  key = {ROUTING_KEY}：路由键 routingKey，direct 交换机根据路由键精准投递消息
     * 3. @Queue：队列定义
     *  @Queue(value = QUEUE_NAME, durable = "true")
     *      value=QUEUE_NAME：队列名称（常量字符串）
     *      durable="true"：队列持久化，RabbitMQ 服务重启队列不丢失；false 临时队列，重启销毁。
     *  可选补充参数：autoDelete="false"没人消费自动删队列、exclusive="false"独占队列。
     * 4. @Exchange：交换机定义
     *  @Exchange(value = EXCHANGE_DIRECT)
     *      value=EXCHANGE_DIRECT：交换机名称
     *  默认类型：DIRECT 直连交换机，不写type属性默认就是ExchangeTypes.DIRECT
     *      补充：type = ExchangeTypes.FANOUT/TOPIC/HEADERS可切换交换机类型
     *  同样自带durable="true"默认持久化，服务重启交换机保留。
     * 5. key = {ROUTING_KEY}：路由键
     *  {}代表数组，支持多个路由键绑定同一个队列
     *  Direct 交换机规则：生产者发消息时routingKey=ROUTING_KEY，消息才会被路由进当前队列。
     * 整体运行逻辑
     * 项目启动 → Spring 自动检测注解 → 自动创建交换机 EXCHANGE_DIRECT、队列 QUEUE_NAME（不存在才创建，幂等不会重复创建）
     * 自动绑定：队列 ↔ 交换机，绑定路由键 ROUTING_KEY
     * 生产者发送消息到交换机 + 指定路由键 = ROUTING_KEY → 消息进入 QUEUE_NAME 队列
     * 队列有消息 → 自动触发被 @RabbitListener 标注的消费方法入参接收消息。
     */
    //@RabbitListener(queues = {QUEUE_ATGUIGU}) 如果交换机，队列右键创建好了，注解就可以这样写
    public void processMessage(String dateString,
                               Message message,
                               Channel channel) {
        log.info(dateString);
    }
  
}