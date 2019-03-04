package com.example.laborator02.Entity;

public class Product extends ObjectToSell {

    private Integer id;
    private String productName;
    private String productDescription;
    private Double productPrice;

    public Product(Integer id, String productName, String productDescription, Double productPrice) {
        super(id, productName, productDescription, productPrice);
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getProductName() {
        return productName;
    }

    public void setProductName(String productName) {
        this.productName = productName;
    }

    public String getProductDescription() {
        return productDescription;
    }

    public void setProductDescription(String productDescription) {
        this.productDescription = productDescription;
    }

    public Double getProductPrice() {
        return productPrice;
    }

    public void setProductPrice(Double productPrice) {
        this.productPrice = productPrice;
    }
}
