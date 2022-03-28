cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)

set(DBUS_LIB CONAN_PKG::dbus)

set(HEADERS
        ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}/Node.hpp)

set(SOURCES
        Node.cpp)

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DBUS_LIB})
