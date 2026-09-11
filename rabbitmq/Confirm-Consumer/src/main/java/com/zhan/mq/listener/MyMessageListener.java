package com.zhan.mq.listener;

import com.rabbitmq.client.Channel;
import lombok.extern.slf4j.Slf4j;
import org.springframework.amqp.core.Message;
import org.springframework.amqp.rabbit.annotation.Exchange;
import org.springframework.amqp.rabbit.annotation.Queue;
import org.springframework.amqp.rabbit.annotation.QueueBinding;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.stereotype.Component;

import java.io.IOException;
import java.util.concurrent.TimeUnit;

@Component
@Slf4j
public class MyMessageListener {

    public static final String EXCHANGE_DIRECT = "exchange.direct.order";
    public static final String ROUTING_KEY = "order";
    public static final String QUEUE_NAME  = "queue.order";
    public static final String QUEUE_NORMAL = "queue.normal.video";
    public static final String QUEUE_DEAD_LETTER = "queue.dead.letter.video";

    // 修饰监听方法
    @RabbitListener(
            // 设置绑定关系
            bindings = @QueueBinding(

                    // 配置队列信息：durable 设置为 true 表示队列持久化；autoDelete 设置为 false 表示关闭自动删除
                    value = @Queue(value = QUEUE_NAME, durable = "true", autoDelete = "false"),

                    // 配置交换机信息：durable 设置为 true 表示队列持久化；autoDelete 设置为 false 表示关闭自动删除
                    exchange = @Exchange(value = EXCHANGE_DIRECT, durable = "true", autoDelete = "false"),

                    // 配置路由键信息
                    key = {ROUTING_KEY}
            ))
    public void processMessage(String dataString, Message message, Channel channel) throws IOException {


        // 1、获取当前消息的 deliveryTag 值备用
        long deliveryTag = message.getMessageProperties().getDeliveryTag();

        try {
            // 2、正常业务操作
            log.info("消费端接收到消息内容：" + dataString);

            // System.out.println(10 / 0);

            // 3、给 RabbitMQ 服务器返回 ACK 确认信息
            channel.basicAck(deliveryTag, false);
        } catch (Exception e) {

            // 4、获取信息，看当前消息是否曾经被投递过
            /**
             * true:当前消息已经重复投递过一次
             * false:当前消息是第一次投递
             */
            Boolean redelivered = message.getMessageProperties().getRedelivered();

            // 核心操作成功，返回ACK信息
            /**
             * requeue 参数：控制消息是否重新放回队列
             *      取值为true:重新放回队列，broker 会重新投递这个消息
             *      取值false:不重新放回队列，broker 会丢弃这个消息
             */
            if (!redelivered) {
                // 5、如果没有被投递过，那就重新放回队列，重新投递，再试一次
                channel.basicNack(deliveryTag, false, true);
            } else {
                // 6、如果已经被投递过，且这一次仍然进入了 catch 块，那么返回拒绝且不再放回队列
                channel.basicReject(deliveryTag, false);
            }

        }
    }

    @RabbitListener(queues = {QUEUE_NAME})
    public void processMessageTestPrefetch(String dataString, Message message, Channel channel) throws IOException, InterruptedException {
        // 1、获取当前消息的 deliveryTag 值备用
        long deliveryTag = message.getMessageProperties().getDeliveryTag();
        // 2、正常业务操作
        log.info("消费端接收到消息内容：" + dataString);

        // System.out.println(10 / 0);
        TimeUnit.SECONDS.sleep(1);

        // 3、给 RabbitMQ 服务器返回 ACK 确认信息
        channel.basicAck(deliveryTag, false);
    }

    @RabbitListener(queues = {QUEUE_NORMAL})
    public void processMessageNormal(Message message, Channel channel) throws IOException {
        // 监听正常队列，但是拒绝消息
        log.info("★[normal]消息接收到，但我拒绝。");
        channel.basicReject(message.getMessageProperties().getDeliveryTag(), false);
    }

    @RabbitListener(queues = {QUEUE_DEAD_LETTER})
    public void processMessageDead(String dataString, Message message, Channel channel) throws IOException {
        // 监听死信队列
        log.info("★[dead letter]dataString = " + dataString);
        log.info("★[dead letter]我是死信监听方法，我接收到了死信消息");
        channel.basicAck(message.getMessageProperties().getDeliveryTag(), false);
    }
}