#include <iostream>
#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <string>


int main (int argc, char **argv) {
    //调用报错函数
    errorCheck();
}

void errorCheck () {
    GLenum errorCode = glGetError();
    std::string error = "";
    if (errorCode != GL_NO_ERROR) {
        switch (errorCode)
        {
        case GL_INVALID_ENUM: error = "GL_INVALID_ENUM";
            break;
        case GL_INVALID_VALUE: error = "GL_INVALID_VALUE";
            break;
        case GL_INVALID_OPERATION: error = "GL_INVALID_OPERATION";
            break;
        case GL_STACK_OVERFLOW: error = "GL_STACK_OVERFLOW";
            break;
        case GL_OUT_OF_MEMORY: error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "Unknown error";
            break;
        }
    }
    std::cout<<error<<std::endl;
}