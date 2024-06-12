#pragma once
#include <iostream>

#define app Application::getInstance()

class GLFWwindow;
//函数指针类型
using ResizeCallBack = void(*)(int width, int height);

class Application {
public:
    ~Application();
    //用于访问实例的静态函数
    static Application* getInstance();

    bool init(const int& width=800, const int& height=600);

    bool update();

    void destroy();
    
    uint32_t getWidth() const { return mWidth; }
    uint32_t getHeight() const { return mHeight; }
    //设置窗口大小改变回调函数
    void setResizeCallBack(ResizeCallBack callback) {mResizeCallBack = callback;}

private:
    //被函数指针指向的窗口响应静态函数
    static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

private:
    //全局唯一静态变量实例
    static Application* mInstance;

    uint32_t mWidth{800};
    uint32_t mHeight{600};
    GLFWwindow* mWindow{nullptr};
    //指向窗口大小改变回调函数的函数指针
    ResizeCallBack mResizeCallBack {nullptr};



    Application();
};