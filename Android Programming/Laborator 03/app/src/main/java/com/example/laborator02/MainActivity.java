package com.example.laborator02;

import android.nfc.Tag;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
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

    @Override
    protected void onStart() {
        super.onStart();
        String startUpMessage = "Application started";
        Toast.makeText(MainActivity.this, startUpMessage, Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onResume() {
        super.onResume();
        String resumedMessage = "Application resumed";
        Toast.makeText(MainActivity.this, resumedMessage, Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onPause() {
        super.onPause();
        String pauseMessage = "Application paused";
        Toast.makeText(MainActivity.this, pauseMessage, Toast.LENGTH_LONG).show();
    }

    @Override
    protected void onStop() {
        super.onStop();
        String stopMessage = "Application stopped. Bye bye!";
        Toast.makeText(MainActivity.this, stopMessage, Toast.LENGTH_LONG).show();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.options_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        if(id == R.id.add_option) {
            Toast.makeText(getApplicationContext(),"Add Options selected",Toast.LENGTH_LONG).show();
            return true;
        }
        else if(id == R.id.user_products_option) {
            Toast.makeText(getApplicationContext(),"User products option selected",Toast.LENGTH_LONG).show();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
