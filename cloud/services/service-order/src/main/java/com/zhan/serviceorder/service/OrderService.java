package com.zhan.serviceorder.service;


import com.zhan.order.Order;

public interface OrderService {
    Order createOrder(Long productId, Long userId);
}
