package com.example.laborator02.Repository;

import com.example.laborator02.Entity.Service;

import java.util.ArrayList;
import java.util.List;

public class ServiceRepository {

    private List<Service> serviceList = new ArrayList<>();

    public List<Service> populateServiceList() {
        serviceList.add(new Service(1, "Uber", "Fuck taxi", 150.30));
        serviceList.add(new Service(2, "Meditatii Mate", "Sa iei bacu", 180.60));
        serviceList.add(new Service(3, "Booking", "Cool hotels", 69.69));
        return serviceList;
    }
}
