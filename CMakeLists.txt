cmake_minimum_required(VERSION 3.21)
project(jcllib)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

include(CTest)
include_directories(include)

add_subdirectory(src)
add_subdirectory(example)

install(DIRECTORY include/
        DESTINATION include)

install(TARGETS ${PROJECT_NAME}
        EXPORT export_${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

if(CMAKE_TESTING_ENABLED)
    add_subdirectory(test)
endif ()
