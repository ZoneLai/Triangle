#include <jni.h>
#include <android/native_window_jni.h>
#include "JniHelper.h"
#include "TriangleManager.h"

#ifndef _Included_com_zone_triangle_TriangleRenderer
#define _Included_com_zone_triangle_TriangleRenderer
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_com_zone_triangle_TriangleRenderer_nativeOnCreate(JNIEnv *env, jclass thiz)
{
	if (TriangleManager::getSingletonPtr() == nullptr) {
        new TriangleManager();
    }
    TriangleManager::getSingleton().onCreate();
}

JNIEXPORT void JNICALL Java_com_zone_triangle_TriangleRenderer_nativeOnResume(JNIEnv *env, jclass thiz)
{
	 TriangleManager::getSingleton().onResume();
}

JNIEXPORT void JNICALL Java_com_zone_triangle_TriangleRenderer_nativeOnPause(JNIEnv *env, jclass thiz)
{
	TriangleManager::getSingleton().onPause();
}

JNIEXPORT void JNICALL Java_com_zone_triangle_TriangleRenderer_nativeOnStop(JNIEnv *env, jclass thiz)
{
	TriangleManager::getSingleton().onStop();
}

JNIEXPORT void JNICALL Java_com_zone_triangle_TriangleRenderer_nativeOnDestroy(JNIEnv *env, jclass thiz)
{
	TriangleManager::getSingleton().onDestroy();
}

JNIEXPORT void JNICALL Java_com_zone_triangle_TriangleRenderer_nativeInitGL(JNIEnv *env, jobject thiz, jint width, jint height)
{
	TriangleManager::getSingleton().initGL(width, height);
}

JNIEXPORT void JNICALL Java_com_zone_triangle_TriangleRenderer_nativeDrawFrame(JNIEnv *env, jclass thiz)
{
	 TriangleManager::getSingleton().drawFrame();
}

JNIEXPORT void JNICALL Java_com_zone_triangle_TriangleRenderer_nativeOnSurfaceChanged(JNIEnv *env, jobject thiz, jint width, jint height)
{
	TriangleManager::getSingleton().onChange(width, height);
}

JNIEXPORT jint JNICALL Java_com_zone_triangle_TriangleRenderer_nativeGetTextureId(JNIEnv *env, jclass thiz)
{
	return TriangleManager::getSingleton().getCameraTextureId();
}

#ifdef __cplusplus
}
#endif
#endif
