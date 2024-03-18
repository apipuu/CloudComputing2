cmake_minimum_required(VERSION 3.9)
project(hello_cpp_docker)
# Set our project to use C++ 17
set(CMAKE_CXX_STANDARD 17)
# Set our source files as just the main.cpp
set(SOURCE_FILES main.cpp)
# Create our executable file from our source files
add_executable(cppdocker_run ${SOURCE_FILES})
