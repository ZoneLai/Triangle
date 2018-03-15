package com.zone.triangle;

import android.content.Context;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * @authon 赖忠安
 * Create on 2018/3/14.
 */

public class TriangleRenderer implements GLSurfaceView.Renderer {
    private static final int MAX_PREVIEW_WIDTH = 1080;
    private static final int MAX_PREVIEW_HEIGHT = 1920;

    static {
        System.loadLibrary("Triangle");
    }

    public TriangleRenderer(Context context) {
        nativeOnCreate();
    }

    @Override
    public void onSurfaceCreated(GL10 gl10, EGLConfig eglConfig) {
        nativeInitGL(MAX_PREVIEW_WIDTH, MAX_PREVIEW_HEIGHT);
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        nativeOnSurfaceChanged(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl10) {
        nativeDrawFrame();
    }

    public void onStop() {
        nativeOnStop();
    }

    public void onDestroy() {
        nativeOnDestroy();
    }


    private static native void nativeOnCreate();

    private static native void nativeOnResume();

    private static native void nativeOnPause();

    private static native void nativeOnStop();

    private static native void nativeOnDestroy();

    private static native void nativeInitGL(int widgetWidth, int widgetHeight);

    private static native void nativeDrawFrame();

    private static native void nativeOnSurfaceChanged(int widgetWidth, int widgetHeight);

    private static native int nativeGetTextureId();
}
