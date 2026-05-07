package com.zhan.serviceorder;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.discovery.DiscoveryClient;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;

@SpringBootTest
public class LoadBalancerTest {

    @Autowired
    LoadBalancerClient loadBalancerClient;
    DiscoveryClient discoveryClient;

    @Test
    void test(){
        ServiceInstance choose = loadBalancerClient.choose("zhan");
        System.out.println(choose.getHost());
        System.out.println(choose.getPort());
        System.out.println(choose.getServiceId());
        System.out.println(choose.getUri());

    }
}
