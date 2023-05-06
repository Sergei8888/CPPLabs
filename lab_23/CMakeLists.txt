cmake_minimum_required(VERSION 3.14)
project(lab_23)
set(CMAKE_CXX_STANDARD 11)

find_package(Catch2 3 REQUIRED)

add_executable(lab_23.cpp main.cpp)
target_link_libraries(lab_23.cpp PRIVATE Catch2::Catch2WithMain)
