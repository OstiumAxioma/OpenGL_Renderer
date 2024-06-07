#pragma once
#include <iostream>
class Application {
public:
    ~Application();
    //用于访问实例的静态函数
    static Application* getInstance();
    void test(){
        std::cout << "test" << std::endl;
    }
private:
    //全局唯一静态变量实例
    static Application* mInstance;
    Application();
};