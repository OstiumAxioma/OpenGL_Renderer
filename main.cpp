#include <iostream>
#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include "wrapper/checkError.h"
#include "application/Application.h"

//响应窗体变化函数
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    std::cout<<"Window size"<<width<<","<<height<<std::endl;
    //更新视口大小
    glViewport(0, 0, width, height);
};

//键盘消息回调函数
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_W){

    }
    if (action == GLFW_PRESS)
    {
        /* code */
    }
    if (action == GLFW_RELEASE)
    {
        /* code */
    }
    if(mods == GLFW_MOD_CONTROL){
        /* code */
    }
    if(mods == GLFW_MOD_SHIFT){
        /* code */
    }
    std::cout<<"press"<<key<<std::endl;
    std::cout<<"action:"<<action<<std::endl;
    std::cout<<"mods:"<<mods<<std::endl; 
    
}
void processInput(GLFWwindow *window);

int main()
{
    if(!app->init(800, 600)){
        return -1;
    };

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

