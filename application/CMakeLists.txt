#递归将本文件夹下所有cpp放到FUNCS中
file(GLOB_RECURSE APP "*.cpp")

#将application所有 cpp 编译为 lib 库
add_library(app ${APP})