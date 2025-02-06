cmake_minimum_required(VERSION 3.10)
project(AVISAAI)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})