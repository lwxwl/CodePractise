package com.example.lwxwl.uiwidgettest;

import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    private EditText edt;
    private ProgressBar progressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = (Button) findViewById(R.id.button);
        EditText edt = (EditText) findViewById(R.id.edt);
        ProgressBar progressBar = (ProgressBar) findViewById(R.id.progressBar);
        button.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.button:
                // int progress = progressBar.getProgress();
                // progress = progress + 10;
                // progressBar.setProgress(progress);
                // break;

                AlertDialog.Builder dialog = new AlertDialog.Builder(MainActivity.this);
                dialog.setTitle("This is Dialog");
                dialog.setMessage("Something important.");
                dialog.setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                    }
                });
                dialog.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                    }
                });
                dialog.show();

                // ProgressDialog progressDialog = new ProgressDialog(MainActivity.this);
                // progressDialog.setTitle("");
                // progressDialog.setMessage("");
                // progressDialog.setCancelable(true);
                // progressDialog.show();
                break;
            default:
                break;
        }
    }
}
