cmake_minimum_required(VERSION 3.21)
project(jcllib)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

include_directories(include)

add_subdirectory(src)
