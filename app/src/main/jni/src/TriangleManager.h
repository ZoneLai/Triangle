#pragma once
#include <time.h>
#include <math.h>
#include <android/log.h>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include "Singleton.h"
#include "android/asset_manager.h"
#include <android/asset_manager_jni.h>
#include <android/native_window_jni.h>
#include "glm.hpp"
#include "ext.hpp"
#include <thread>
#include "JniHelper.h"
class TriangleManager : public Singleton<TriangleManager> {
public:
    TriangleManager();
    ~TriangleManager();
    void                        onCreate();
    void                        onResume();
    void                        onPause();
    void                        onStop();
    void                        onDestroy();
    void                        initGL(float width, float height);
    void                        drawFrame();
    GLint                       getCameraTextureId();

private:
    GLuint                      _sProgramPlay;
    GLuint						_vaoId;
    GLuint						_vboBuffer;
    GLint						_positionLoc;
    GLint						_colorLoc;
    GLint						_mvpMatrixLoc;
    glm::mat4                   _mvpMatrix;
};