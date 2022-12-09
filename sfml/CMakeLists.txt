cmake_minimum_required(VERSION 3.14)
project(KuramotoModel)

set(CMAKE_CXX_STANDARD 11)
include_directories(./libs/SFML/Frameworks/include)

set(SFML_DIR ./libs/SFML/Frameworks/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

add_executable(KuramotoModel ./src/main.cpp)

target_link_libraries(KuramotoModel sfml-system sfml-window sfml-graphics sfml-audio sfml-network)