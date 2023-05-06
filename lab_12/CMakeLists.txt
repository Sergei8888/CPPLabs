cmake_minimum_required(VERSION 3.14)
project(KuramotoModel)

set(CMAKE_CXX_STANDARD 11)

add_executable(Uniscope ./src/main.cpp)

# Installing sfml
include_directories(./libs/SFML/Frameworks/include)
set(SFML_DIR ./libs/SFML/Frameworks/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(Uniscope sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Installing openssl
include_directories(./libs/openssl-openssl-3.0.0/include)
set(OPENSSL_ROOT_DIR ./libs/openssl-openssl-3.0.0)
find_package(OpenSSL)
target_link_libraries(Uniscope OpenSSL::SSL OpenSSL::Crypto)

# Installing json
include_directories(./libs/json/include)

# Installing socket-io-client
include_directories(./libs/socket.io-client-cpp/src)
find_package(sioclient CONFIG REQUIRED)
target_link_libraries(Uniscope sioclient::sioclient sioclient::sioclient_tls)

