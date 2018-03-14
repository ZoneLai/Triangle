#include "Common.h"
#include "TriangleManager.h"
#include "GLUtil.h"
#include "shader/camera.frag"
#include "shader/camera.vert"
/* GL_OES_EGL_image_external */
#ifndef GL_OES_EGL_image_external
#define GL_TEXTURE_EXTERNAL_OES                                 0x8D65
#endif
template<> TriangleManager* Singleton<TriangleManager>::msSingleton = nullptr;
TriangleManager::TriangleManager()
    : _sProgramPlay(0)
    , _vaoId(0)
    , _vboBuffer(0)
    , _positionLoc(-1)
    , _colorLoc(-1)
    , _mvpMatrixLoc(-1)
    , _mvpMatrix(glm::mat4(1.0f))
{
}

TriangleManager::~TriangleManager() {
}

void TriangleManager::onCreate() {
}

void TriangleManager::onResume() {
}

void TriangleManager::onPause() {
}

void TriangleManager::onStop() {
}

void TriangleManager::onDestroy() {
    glDeleteVertexArrays(1, &_vaoId);
    glDeleteBuffers(1, &_vboBuffer);
    glDeleteProgram(_sProgramPlay);
}

void TriangleManager::initGL(float width, float height) {
    if (CompileShaderProgram(camera_play_vert, camera_play_frag, &_sProgramPlay)) {
        _positionLoc	    = glGetAttribLocation(_sProgramPlay,    "a_Position");
        _colorLoc		    = glGetAttribLocation(_sProgramPlay,    "a_Color");
        _mvpMatrixLoc       = glGetUniformLocation(_sProgramPlay,   "u_MvpMatrix");
        GLfloat vertices[]  = {
            -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
             0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
             0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
        };
        glGenVertexArrays(1, &_vaoId);
        glBindVertexArray(_vaoId);
        glGenBuffers(1, &_vboBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, _vboBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(
            _positionLoc,
            3,
            GL_FLOAT,
            GL_FALSE,
            6 * sizeof(GL_FLOAT),
            (GLvoid*)0
        );
        glEnableVertexAttribArray(_positionLoc);
        glVertexAttribPointer(
            _colorLoc,
            3,
            GL_FLOAT,
            GL_FALSE,
            6 * sizeof(GL_FLOAT),
            (GLvoid*)(3 * sizeof(GL_FLOAT))
        );
        glEnableVertexAttribArray(_colorLoc);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    } else {
        LOGE("CompileShaderProgram===================");
    }
}

void TriangleManager::drawFrame() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(_vaoId);
    glUseProgram(_sProgramPlay);
    glUniformMatrix4fv(_mvpMatrixLoc, 1, GL_FALSE, glm::value_ptr(_mvpMatrix));
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    glUseProgram(0);
}

GLint TriangleManager::getCameraTextureId() {
    return 0;
}