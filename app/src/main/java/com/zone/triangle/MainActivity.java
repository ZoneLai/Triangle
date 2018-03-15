package com.zone.triangle;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    TriangleSurfaceView mTriangleSurfaceView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
        mTriangleSurfaceView = new TriangleSurfaceView(this, null);
        setContentView(mTriangleSurfaceView);
    }

    @Override
    protected void onStop() {
        super.onStop();
        mTriangleSurfaceView.onStop();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mTriangleSurfaceView.onDestroy();
    }
}
