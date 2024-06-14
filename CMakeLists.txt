cmake_minimum_required(VERSION 3.5.0)
project(cmake_vscode VERSION 0.1.0 LANGUAGES C CXX)

# 使用C++ 11标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 加入项目全局调试宏-D+宏名称
add_definitions(-DDEBUG) # 注释以关闭调试

# 添加Homebrew include和lib路径（如果需要）
# include_directories(/opt/homebrew/include)
# link_directories(/opt/homebrew/lib)

# 找到GLFW库
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

# 设置GLAD的头文件路径
set(GLAD_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/thirdparty)
include_directories(${GLAD_INCLUDE_DIR})

# 添加GLAD的源文件
add_library(glad STATIC ${PROJECT_SOURCE_DIR}/glad.c)

link_directories(${PROJECT_SOURCE_DIR}/lib)

# 添加次级目录
add_subdirectory(wrapper)
add_subdirectory(application)

# 添加可执行文件和源文件
add_executable(cmake_vscode main.cpp glad.c)

# 链接GLFW库和GLAD库以及其他系统库
target_link_libraries(cmake_vscode glfw glad wrapper app "-framework Cocoa" "-framework IOKit" "-framework CoreFoundation" "-framework CoreVideo" "-framework Carbon" "-framework QuartzCore")



# 包含测试和打包设置
include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)