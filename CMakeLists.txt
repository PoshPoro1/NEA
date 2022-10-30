cmake_minimum_required(VERSION 3.0.0)
project(NEA VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

add_executable(NEA src/main.cpp src/glad.c src/shader.cpp src/controls.cpp)
target_include_directories(NEA PRIVATE include) 

target_link_libraries(NEA glfw glm)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
file(COPY Shaders
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
