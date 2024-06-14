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

//初始化 VBO
void prepareVBO()
{
    //创建一个 VBO，未分配显存
    GLuint VBO; //使用 GLuint 类型的变量存储 VBO 的 ID
    GL_CALL(glGenBuffers(1, &VBO)); //生成一个 VBO, 并储存地址到 VBO 变量中

    //销毁一个 VBO
    GL_CALL(glDeleteBuffers(1, &VBO)); //销毁一个 VBO

    //创建 3 个 VBO，未分配显存
    GLuint VBOs[3] = {0, 0, 0}; //使用 GLuint 类型的数组存储 VBO 的 ID
    GL_CALL(glGenBuffers(3, VBOs)); //生成 3 个 VBO, 并储存地址到 VBOs 数组中

    //销毁 3 个 VBO
    GL_CALL(glDeleteBuffers(3, VBOs)); //销毁 3 个 VBO
}

//绑定 VBO
void bindVBO()
{
    //1. 生成一个 VBO
    //2. 绑定当前 VBO 到 openGL 状态机的当前 VBO 插槽
    //3. 向当先 VBO 插槽写入数据 （此处以顶点坐标为例），开辟显存空间

    //顶点坐标数据
    float vertices[] = {
        0.5f, 0.5f, 0.0f, // 右上角
        0.5f, -0.5f, 0.0f, // 右下角
        -0.5f, -0.5f, 0.0f, // 左下角
        -0.5f, 0.5f, 0.0f // 左上角
    };
    //1. 创建一个 VBO，未分配显存
    GLuint VBO; //使用 GLuint 类型的变量存储 VBO 的 ID
    GL_CALL(glGenBuffers(1, &VBO)); //生成一个 VBO, 并储存地址到 VBO 变量中

    //2. 绑定到 VBO 插槽
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, VBO)); //GL_ARRAY_BUFFER表示当前 VBO 插槽

    //3. 向 VBO 插槽写入数据开辟显存空间
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW)); //GL_STATIC_DRAW表示数据不会或几乎不会改变, GL_DYNAMIC_DRAW表示数据会被改变很多

    //
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

    //prepareVBO();
    bindVBO();

    //执行窗体循环
    while (app->update())
    {
        GL_CALL(glClear(GL_COLOR_BUFFER_BIT)); //清理颜色缓冲区 GL_CALL是调试宏  
    }
    app->destroy();
    return 0;
}

