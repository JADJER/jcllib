cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 23)

set(DBUS_LIB CONAN_PKG::dbus)
set(LOGGER_LIB CONAN_PKG::logger)

set(HEADERS_PATH ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME})

set(HEADERS
        ${HEADERS_PATH}/Node.hpp
        ${HEADERS_PATH}/Client.hpp
        ${HEADERS_PATH}/Service.hpp
        ${HEADERS_PATH}/Connection.hpp

        ${HEADERS_PATH}/exception/NotConnectionException.hpp
        )

set(SOURCES
        Node.cpp
        Client.cpp
        Service.cpp
        Connection.cpp
        )

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC ${DBUS_LIB})
target_link_libraries(${PROJECT_NAME} PUBLIC ${LOGGER_LIB})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
