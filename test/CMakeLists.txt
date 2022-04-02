cmake_minimum_required(VERSION 3.21)

set(TEST_NAME ${PROJECT_NAME}_test)

set(CATCH2_LIB CONAN_PKG::catch2)
set(JCL_LIB jcllib)

set(SOURCES
        node_test.cpp
        client_test.cpp)

add_executable(${TEST_NAME} main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME}_test ${CATCH2_LIB})
target_link_libraries(${PROJECT_NAME}_test ${JCL_LIB})

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
