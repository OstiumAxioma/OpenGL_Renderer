#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Application* Application::mInstance = nullptr;
Application* Application::getInstance()
{
    if (mInstance == nullptr)
    {
        mInstance = new Application();
    }
    return mInstance;
}
Application::Application()
{
}

Application::~Application()
{
}

bool Application::init(const int& width, const int& height)
{
    mWidth = width;
    mHeight = height;
    //初始化GLFW环境
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //设置主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //设置次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //设置OpenGL配置文件核心模式
    #ifdef __APPLE__
    //如果使用的是Mac OS X系统，你还需要加下面这行代码到你的初始化代码中这些配置才能起作用
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    //创建窗口对象
    mWindow = glfwCreateWindow(mWidth, mHeight, "OpenGL Renderer", NULL, NULL);

    if (mWindow == NULL)
    {
        std::cout << "fail to create window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(mWindow); //将该窗口为绘制环境

    //glad 加载openGL函数
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "fail to init glad" << std::endl;
        return false;
    }

    glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallback); //初始化时调用设置窗口大小改变回调函数

    return true;
}

bool Application::update()
{
    if(glfwWindowShouldClose(mWindow))
    {
        return false;
    }
    //渲染操作
    glfwPollEvents(); //轮询事件
    glfwSwapBuffers(mWindow); //交换双重缓冲区
    return true;
}

void Application::destroy()
{
    glfwTerminate(); //终止GLFW
    return;
}
//实现窗口大小改变回调函数
void Application::frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    std::cout << "Resize" << std::endl;
    if(Application::getInstance()->mResizeCallBack != nullptr)
    {
        Application::getInstance()->mResizeCallBack(width, height);//调用回调函数
    }
}