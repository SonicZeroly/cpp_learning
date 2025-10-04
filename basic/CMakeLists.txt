cmake_minimum_required(VERSION 3.30)
project(basic)

set(CMAKE_CXX_STANDARD 17)  

include_directories("inc")  #使用"/inc"是从根目录开始找

file(GLOB INCLUDES "inc/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(app main.cpp ${SOURCES}) #变量需要用${}来取值

# cmake成功运行但vscode编辑区仍报错，可尝试重新打开