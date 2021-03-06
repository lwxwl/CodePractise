package com.example.lwxwl.androidtest;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class FirstActivity extends BaseActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d("FirstActivity", this.toString());
        setContentView(R.layout.first_layout);
        Button button1 = (Button) findViewById(R.id.button_1);
        button1.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                SecondActivity.actionStart(FirstActivity.this, "data1", "data2");
                // Toast.makeText(FirstActivity.this, "You clicked Button 1", Toast.LENGTH_SHORT).show();
                // finish();  销毁活动

                // 显式Intent
                // Intent intent = new Intent(FirstActivity.this, SecondActivity.class);
                // startActivity(intent);

                // 隐式Intent
                // Intent intent = new Intent("com.example.lwxwl.androidtest.ACTION_START");
                // intent.addCategory("com.example.lwxwl.androidtest.MY_CATEGORY");
                // startActivity(intent);

                // 打开浏览器，但并无加载并显示网页的功能
                // Intent intent = new Intent(Intent.ACTION_VIEW);
                // intent.setData(Uri.parse("http://www.baidu.com"));
                // startActivity(intent);

                // 调用系统拨号界面
                // Intent intent = new Intent(Intent.ACTION_DIAL);
                // intent.setData(Uri.parse("tel:10086"));
                // startActivity(intent);

                // 向SecondActivity传递数据
                // String data = "Hello SecondActivity";
                // Intent intent = new Intent(FirstActivity.this, SecondActivity.class);
                // intent.putExtra("extra_data", data);
                // startActivity(intent);

                // 获取SecondActivity返回的数据
                // Intent intent = new Intent(FirstActivity.this, SecondActivity.class);
                // startActivityForResult(intent, 1);

                // 活动的启动模式standard, singleTop, singleTask, singleInstance
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch(item.getItemId()){
            case R.id.add_item:
                Toast.makeText(this, "You clicked Add", Toast.LENGTH_SHORT).show();
                break;
            case R.id.remove_item:
                Toast.makeText(this, "You clicked Remove", Toast.LENGTH_SHORT).show();
                break;
            default:
        }
        return true;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        switch(requestCode){
            case 1:
                if(resultCode == RESULT_OK){
                    String returnedData = data.getStringExtra("data_returned");
                    Log.d("FirstActivity", returnedData);
                }
                break;
            default:
        }


    }
}
