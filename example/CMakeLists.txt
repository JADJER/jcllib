cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)

set(EXAMPLE_NAME ${PROJECT_NAME}_example)

set(JCL_LIB ${PROJECT_NAME})

set(HEADERS
        PingPong.hpp)

set(SOURCES
        main.cpp
        PingPong.cpp)

add_executable(${EXAMPLE_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${EXAMPLE_NAME} ${JCL_LIB})
