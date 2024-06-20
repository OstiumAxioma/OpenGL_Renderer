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
GLuint VBO, VAO, shaderProgram;
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
}

//多属性分别绑定 VBO
void singleBufferVBO()
{
    //1. 准备顶点位置与颜色数据
    //2. 为位置&颜色数据分别创建 VBO
    //3. 给两个 VBO 分别填充数据

    //1.1 三角顶点位置数据
    float positions[] = {
        -0.5f, -0.5f, 0.0f, // 左下角
        0.5f, -0.5f, 0.0f, // 右下角
        0.0f, 0.5f, 0.0f // 上中角
    };

    //1.2 三角顶点颜色数据
    float colors[] = {
        1.0f, 0.0f, 0.0f, // 左下角
        0.0f, 1.0f, 0.0f, // 右下角
        0.0f, 0.0f, 1.0f // 上中角
    };

    //2.1 创建位置 VBO
    GLuint posVBO;
    GL_CALL(glGenBuffers(1, &posVBO));

    //2.2 创建颜色 VBO
    GLuint colorVBO;
    GL_CALL(glGenBuffers(1, &colorVBO));

    //3.1 绑定位置 VBO
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, posVBO));

    //3.2 绑定颜色 VBO
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, colorVBO));

    //3.3 填充位置 VBO
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW));

    //3.4 填充颜色 VBO
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW));

}

//多属性交叉绑定 VBO
void interleavedBufferVBO()
{
    //1. 准备顶点位置与颜色数据
    //2. 为位置&颜色数据创建一个 VBO
    //3. 给 VBO 填充数据

    //1. 三角顶点位置与颜色数据
    float vertices[] = {
        // 位置              // 颜色
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // 左下角, 红色
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // 右下角, 绿色
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // 上中角, 蓝色
    };

    //2. 创建一个 VBO
    GLuint VBO = 0;
    GL_CALL(glGenBuffers(1, &VBO));

    //3. 绑定 VBO
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, VBO));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));
}

//多属性分别绑定 VBO 并构建 VAO 
void singleBufferVAO()
{
    //1. 准备顶点位置与颜色数据
    //2. 为位置&颜色数据分别创建 VBO 并绑定
    //3. 创建 VAO 并绑定
    //4. 向 VAO 压入描述信息

    //1.1 三角顶点位置数据
    float positions[] = {
        -0.5f, -0.5f, 0.0f, // 左下角
        0.5f, -0.5f, 0.0f, // 右下角
        0.0f, 0.5f, 0.0f // 上中角
    };

    //1.2 三角顶点颜色数据
    float colors[] = {
        1.0f, 0.0f, 0.0f, // 左下角
        0.0f, 1.0f, 0.0f, // 右下角
        0.0f, 0.0f, 1.0f // 上中角
    };

    //2.1 创建 VBO
    GLuint posVBO;
    GL_CALL(glGenBuffers(1, &posVBO));

    GLuint colorVBO;
    GL_CALL(glGenBuffers(1, &colorVBO));

    //2.2 绑定 VBO
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, posVBO));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, colorVBO));

    //2.3 填充 VBO 数据
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW));

    //3.1 创建 VAO
    GLuint VAO;
    GL_CALL(glGenVertexArrays(1, &VAO));

    //3.2 绑定 VAO
    GL_CALL(glBindVertexArray(VAO));

    //4.1 压入位置数据
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, posVBO));//注意，接下来的操作全部都是基于当前绑定的 VBO，如果要操作别的 VBO，需要重新绑定
    GL_CALL(glEnableVertexAttribArray(0));//启用VAO的 0 号index，接下来 posVBO 的数据会压入到 0 号 index
    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));//偏移量strip为 3 * sizeof(float)，因为位置数据XYZ为 3 个 float 一个跨度

    //4.2 压入颜色数据
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, colorVBO));//重新绑定 colorVBO
    GL_CALL(glEnableVertexAttribArray(1));//启用VAO的 1 号index，接下来 colorVBO 的数据会压入到 1 号 index
    GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));//注意，这里的 stride 为 3 * sizeof(float)，因为颜色数据 RGB 共 3 个 float 一个跨度

    //5. 解绑 VAO
    glBindVertexArray(0);

}

void prepareShader()
{
    //1. 建立 Shader 片段
    //定义顶点着色器 Vertex Shader
        const char* vertexShaderSource =
        "#version 410 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    //定义片元着色器 Fragment Shader
        const char* fragmentShaderSource =
        "#version 410 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";

    //2. 创建 Shader 程序
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //3. 为 Shader 程序输入 Shader 代码
    //glShaderSource 函数用来为 Shader 对象上传 Shader 代码
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//"\0"结尾不需要告知字符串长度
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

    //创建错误信息储存变量
    int success = 0;
    char infoLog[1024];
    //4. 编译 Shader 程序
    glCompileShader(vertexShader);
    //检查编译错误
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 1024, NULL, infoLog);
        std::cout<<"ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"<<infoLog<<std::endl;
    }

    glCompileShader(fragmentShader);
    //检查编译错误
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 1024, NULL, infoLog);
        std::cout<<"ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"<<infoLog<<std::endl;
    }

    //5. 建立 Shader 程序Shell
    shaderProgram = 0;
    shaderProgram = glCreateProgram();

    //6. 放入 Shader 编译结果
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    //7. 链接 Shader 程序成为可执行程序
    glLinkProgram(shaderProgram);
    //检查链接错误
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram, 1024, NULL, infoLog);
        std::cout<<"ERROR::SHADER::PROGRAM::LINK_FAILED\n"<<infoLog<<std::endl;
    }

    //8. 清理 Shader 程序
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void prepareInterleavedBuffer()
{
    //交叉创建顶点与颜色数据
    float vertices[] = {
        // 位置              // 颜色
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // 左下角, 红色
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // 右下角, 绿色
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // 上中角, 蓝色
    };

    //1. 创建一个 VBO
    VBO = 0;
    GL_CALL(glGenBuffers(1, &VBO));

    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, VBO));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));

    VAO = 0;
    GL_CALL(glGenVertexArrays(1, &VAO));
    GL_CALL(glBindVertexArray(VAO));
    //绑定 VBO
    GL_CALL((glBindBuffer(GL_ARRAY_BUFFER, VBO)));
    //设置顶点属性指针
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0));
    //设置颜色属性指针
    GL_CALL(glEnableVertexAttribArray(1));
    GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))));

    //解绑 VAO
    GL_CALL(glBindVertexArray(0));
}

void prepareVAOForGLTriangle()
{
    //1. 准备顶点数据
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // 左下角
        0.5f, -0.5f, 0.0f, // 右上角
        0.0f, 0.5f, 0.0f, // 右下角
        0.5f, 0.5f, 0.0f // 左下角
    };

    //2. 创建一个 VBO
    VBO = 0;
    GL_CALL(glGenBuffers(1, &VBO));

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //3. 创建一个 VAO并绑定
    GL_CALL(glGenVertexArrays(1, &VAO));
    GL_CALL(glBindVertexArray(VAO));

    //4. 描述位置属性
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));

    //5. 解绑 VAO
    glBindVertexArray(0);

}

void render()
{
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT)); //清理颜色缓冲区 GL_CALL是调试宏  

    //1. 绑定当前 program
    glUseProgram(shaderProgram);

    //2. 绑定 VAO
    GL_CALL(glBindVertexArray(VAO));

    //3. 绘制图形
    GL_CALL(glDrawArrays(GL_TRIANGLES, 0, 3));

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
    //bindVBO();
    //singleBufferVBO();
    //interleavedBufferVBO();
    
    prepareShader();
    //singleBufferVAO();
    //prepareInterleavedBuffer();
    prepareVAOForGLTriangle();

    //执行窗体循环
    while (app->update())
    {
        render();
    }
    app->destroy();
    return 0;
}

