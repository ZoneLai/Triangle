package com.zone.triangle;

import android.content.Context;
import android.opengl.GLSurfaceView;

/**
 * @authon 赖忠安
 * Create on 2018/3/14.
 */

public class TriangleSurfaceView extends GLSurfaceView {
    private Context mContext;
    private TriangleRenderer mRenderer;

    public TriangleSurfaceView(Context context) {
        super(context);
        mContext = context;
        setEGLContextClientVersion(2);
        mRenderer = new TriangleRenderer(context);
        setRenderer(mRenderer);
    }

    @Override
    public void onResume() {
        super.onResume();
    }

    @Override
    public void onPause() {
        super.onPause();
    }

    public void onStop() {
        mRenderer.onStop();
    }

    protected void onDestroy() {
        mRenderer.onDestroy();
    }

}
