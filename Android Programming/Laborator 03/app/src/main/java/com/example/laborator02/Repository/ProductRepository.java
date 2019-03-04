package com.example.laborator02.Repository;

import com.example.laborator02.Entity.Product;

import java.util.ArrayList;
import java.util.List;

public class ProductRepository {

    private List<Product> productList = new ArrayList<>();

    public List<Product> populateProductList() {
        productList.add(new Product(1, "Samsung Galaxy S10", "Este cool", 4500.00));
        productList.add(new Product(2, "Iphone X", "Este misto", 6500.20));
        productList.add(new Product(3, "Asus Rgoue", "For gamming", 2500.70));
        productList.add(new Product(4, "Lenovo B51-80", "For business", 2510.62));
        productList.add(new Product(5, "Huawei P10 Lite", "Meh", 1187.81));
        return productList;
    }
}
