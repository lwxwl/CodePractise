package com.example.lwxwl.uilayouttest;

import android.app.Activity;
import android.content.Context;
import android.support.v7.widget.LinearLayoutCompat;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
/**
 * Created by lwxwl on 2017/4/8.
 */

public class TitleLayout extends LinearLayoutCompat {

    public TitleLayout(Context context, AttributeSet attributeSet){
        super(context, attributeSet);
        LayoutInflater.from(context).inflate(R.layout.title, this);
        Button titleBack = (Button) findViewById(R.id.title_back);
        Button titleEdit = (Button) findViewById(R.id.title_edit);
        titleBack.setOnClickListener(new OnClickListener(){
            @Override
            public void onClick(View view) {
                ((Activity) getContext()).finish();
            }
        });
        titleEdit.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getContext(), "You clicked Edit button", Toast.LENGTH_SHORT).show();
            }
        });

    }
}
