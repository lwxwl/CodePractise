package com.example.administrator.listviewtest;

import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends Activity {
    private List<Fruit> fruitList=new ArrayList<Fruit>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initFruits();
        FruitAdapter adapter=new FruitAdapter(MainActivity.this,R.layout.fruit_item,fruitList);
        ListView ListView=(ListView) findViewById(R.id.list_view);
        ListView.setAdapter(adapter);
    }
    private void initFruits(){
        Fruit apple=new Fruit("Apple",R.drawable.apple_pic);
        fruitList.add(apple);
        Fruit banana=new Fruit("Banana",R.drawable.banana_pic);
        fruitList.add(banana);
        Fruit orange=new Fruit("Orange",R.drawable.orange_pic);
        fruitList.add(orange);
        Fruit watermalon=new Fruit("Watermalon",R.drawable.watermalon_pic);
        fruitList.add(watermalon);
        Fruit grape=new Fruit("Grape",R.drawable.grape_pic);
        fruitList.add(grape);
        Fruit pineapple=new Fruit("Pineapple",R.drawable.pineapple_pic);
        fruitList.add(pineapple);
        Fruit strawberry=new Fruit("Strawberry",R.drawable.strawberry_pic);
        fruitList.add(strawberry);
        Fruit lemon=new Fruit("Lemon",R.drawable.lemon_pic);
        fruitList.add(lemon);
        Fruit mango=new Fruit("Mango",R.drawable.mango_pic);
        fruitList.add(mango);
    }
}
