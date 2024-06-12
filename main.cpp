#include <iostream>
#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include "wrapper/checkError.h"
#include "application/Application.h"

//调用Application类的窗口回调函数静态实例
void OnResize(int width, int height)
{
    GL_CALL(glViewport(0,0, width, height));
    std::cout<<"OnResize"<<std::endl;
}

int main()
{
    if(!app->init(800, 600)){
        return -1;
    };

    app->setResizeCallBack(OnResize);

    //设置 OpenGL 视口以及清理颜色
    glViewport(0, 0, 800, 600);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //执行窗体循环
    while (app->update())
    {
        GL_CALL(glClear(GL_COLOR_BUFFER_BIT)); //清理颜色缓冲区 GL_CALL是调试宏  
    }
    app->destroy();
    return 0;
}

