#递归将本文件夹下所有cpp放到WRAPPER中
file(GLOB_RECURSE FUNCS "*.cpp")

#将WRAPPER所有 cpp 编译为 lib 库
add_library(wrapper ${FUNCS})