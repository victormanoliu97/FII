package com.example.laborator02.Entity;

public class Service extends ObjectToSell{

    private Integer id;
    private String serviceName;
    private String serviceDescription;
    private Double servicePrice;

    public Service(Integer id, String serviceName, String serviceDescription, Double servicePrice) {
        super(id, serviceName, serviceDescription, servicePrice);
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getServiceName() {
        return serviceName;
    }

    public void setServiceName(String serviceName) {
        this.serviceName = serviceName;
    }

    public String getServiceDescription() {
        return serviceDescription;
    }

    public void setServiceDescription(String serviceDescription) {
        this.serviceDescription = serviceDescription;
    }

    public Double getServicePrice() {
        return servicePrice;
    }

    public void setServicePrice(Double servicePrice) {
        this.servicePrice = servicePrice;
    }
}
