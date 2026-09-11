package com.zhan.product;

import lombok.Data;

import java.math.BigDecimal;

@Data
public class Product {
    private Long id;
    private String ProductName;
    private BigDecimal Price;
    private int num;
}
