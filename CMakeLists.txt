cmake_minimum_required(VERSION 3.10)
project(AutoAlgo)

add_subdirectory(algorithms)

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE Algorithms)
target_include_directories(MyApp PRIVATE base)
