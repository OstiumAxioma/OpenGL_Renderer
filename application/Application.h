#pragma once
#include <iostream>

#define app Application::getInstance()

class GLFWwindow;

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
private:
    //全局唯一静态变量实例
    static Application* mInstance;

    uint32_t mWidth{800};
    uint32_t mHeight{600};
    GLFWwindow* mWindow{nullptr};
    Application();
};