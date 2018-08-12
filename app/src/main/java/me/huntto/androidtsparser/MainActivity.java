package me.huntto.androidtsparser;

import android.content.res.AssetManager;
import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        new Thread(new Runnable() {
            @Override
            public void run() {
                AssetManager assetManager = getResources().getAssets();
                openTS(assetManager, "NativeMedia.ts");
            }
        }).start();
    }

    public native void openTS(AssetManager assetManager, String filename);
}
