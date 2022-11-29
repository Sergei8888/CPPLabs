cmake_minimum_required(VERSION 3.23)
project(hardend)
set(CMAKE_CXX_STANDARD 14)

include(./conanbuildinfo.cmake)
conan_basic_setup()

add_executable(SFMLTest src/main.cpp)
target_link_libraries(SFMLTest ${CONAN_LIBS})