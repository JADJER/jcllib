cmake_minimum_required(VERSION 3.21)

set(CATCH2_LIB CONAN_PKG::catch2)

set(SOURCES
        node_test.cpp)

add_executable(${PROJECT_NAME}_test main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME}_test ${CATCH2_LIB})
