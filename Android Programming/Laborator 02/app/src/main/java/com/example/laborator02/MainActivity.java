package com.example.laborator02;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import com.example.laborator02.Entity.ObjectToSell;
import com.example.laborator02.Repository.ProductRepository;
import com.example.laborator02.Repository.ServiceRepository;

import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Stream;

public class MainActivity extends AppCompatActivity {

    private ProductRepository productRepository = new ProductRepository();
    private ServiceRepository serviceRepository = new ServiceRepository();

    private ObjectToSell[] objectToSells = Stream.concat(Arrays.stream(productRepository.populateProductList().toArray()), Arrays.stream(serviceRepository.populateServiceList().toArray())).toArray(ObjectToSell[]::new);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        createListView();
        registerClickCallBack();
    }

    public void createListView() {
        ArrayAdapter<ObjectToSell> adapter = new ArrayAdapter<>(
                this,
                R.layout.item_details_layout,
                objectToSells
        );
        ListView listView = findViewById(R.id.productViewList);
        listView.setAdapter(adapter);
    }

    private void registerClickCallBack() {
        ListView listView = findViewById(R.id.productViewList);
        listView.setOnItemClickListener((parent, viewClicked, position, id) -> {
            String name = objectToSells[(int) id].getName();
            Double price = objectToSells[(int) id].getPrice();
            String description = objectToSells[(int) id].getDescription();
            String type = objectToSells[(int) id].getClass().getCanonicalName();
            int lastIndexDot = Objects.requireNonNull(type).lastIndexOf('.');
            String message = type.substring(lastIndexDot + 1).trim() + " " + "Name: " + name + " " + "Price: " + price + " " + "Description: " + description;

            Toast.makeText(MainActivity.this, message, Toast.LENGTH_LONG).show();
        });
    }
}
