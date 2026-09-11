package com.zhan.serviceproduct.service.impl;
import java.math.BigDecimal;

import com.zhan.product.Product;
import com.zhan.serviceproduct.service.ProductService;
import org.springframework.stereotype.Service;

@Service
public class ProductServiceImpl implements ProductService {
    @Override
    public Product getProductById(Long id) {
        Product product = new Product();
        product.setId(id);
        product.setProductName("苹果-"+product);
        product.setPrice(new BigDecimal("99"));
        product.setNum(2);

        return product;
    }
}
