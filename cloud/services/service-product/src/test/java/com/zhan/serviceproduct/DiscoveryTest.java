package com.zhan.serviceproduct;

import com.alibaba.cloud.nacos.discovery.NacosServiceDiscovery;
import com.alibaba.nacos.api.exception.NacosException;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.discovery.DiscoveryClient;

import java.util.List;

@SpringBootTest
public class DiscoveryTest {

    @Autowired
    private DiscoveryClient discoveryClient;//springboot官方的，测试什么注册中心都可以

    @Autowired
    NacosServiceDiscovery nacosServiceDiscovery;//nacos特有的

    @Test
    void nacosDiscoveryTest() throws NacosException {
        for (String service : nacosServiceDiscovery.getServices()) {
            System.out.println("service = "+service);
            List<ServiceInstance> instances = nacosServiceDiscovery.getInstances(service);
            for (ServiceInstance instance : instances) {
                System.out.println("ip:"+instance.getHost()+",port:"+instance.getPort());
            }
        }
    }

    @Test
    void discoveryTest(){
        for(String name:discoveryClient.getServices()){
            System.out.println(name);
            //获取ip+port
            List<ServiceInstance> instances = discoveryClient.getInstances(name);
            for(ServiceInstance instance:instances){
                System.out.println(instance.getHost()+":"+instance.getPort());
            }
        }
    }
}
