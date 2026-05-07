package com.zhan.serviceorder.service.impl;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.List;

import com.zhan.order.Order;
import com.zhan.product.Product;
import com.zhan.serviceorder.service.OrderService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.discovery.DiscoveryClient;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

@Slf4j
@Service
public class OrderServiceImpl implements OrderService {

    @Autowired
    DiscoveryClient discoveryClient;

    @Autowired
    RestTemplate restTemplate;
    @Autowired
    LoadBalancerClient loadBalancerClient;

    @Override
    public Order createOrder(Long productId, Long userId) {
        Product product = getProductFromRemote(productId);
        Order order = new Order();
        order.setId(1L);
        order.setTotalAmount(new BigDecimal("0"));
        order.setUserId(userId);
        order.setNickname("zhangsan");
        order.setAddress("zhan");
        order.setProductList(Arrays.asList(product));
        return order;
    }

    private Product getProductFromRemote(Long productId) {
        loadBalancerClient.choose("service-product");
        //1.获取到商品服务所在服务的所有机器IP+Port
        List<ServiceInstance> instances = discoveryClient.getInstances("service-product");
        ServiceInstance instance = instances.get(0);
        String url = "http://"+instance.getHost()+":"+instance.getPort()+"/product/"+productId;
        log.info("远程调用");
        //2.给远程发送请求
        return restTemplate.getForObject(url, Product.class);

    }

    private Product getProductRemoteWithLoadBalanceAnnotation(Long productId){
        String url = "http://service-product/product/"+productId;
        //给远程发送请求：service-product会被动态替换
        Product product = restTemplate.getForObject(url, Product.class);
        return product;
    }

    private Product getProductFromRemoteWithLoadBalance(Long productId) {
        //1.获取到商品服务所在服务的所有机器IP+Port
        List<ServiceInstance> instances = discoveryClient.getInstances("service-product");
        ServiceInstance instance = instances.get(0);
        String url = "http://"+instance.getHost()+":"+instance.getPort()+"/product/"+productId;
        log.info("远程调用");
        //2.给远程发送请求
        return restTemplate.getForObject(url, Product.class);

    }

}
