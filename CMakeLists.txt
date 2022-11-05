cmake_minimum_required(VERSION 3.24)
project(NEA VERSION 0.1.0)

include(CTest)
include (FetchContent)
enable_testing()


FetchContent_Declare(
	glfw3
	GIT_REPOSITORY https://github.com/glfw/glfw
	GIT_TAG	       7482de6071d21db77a7236155da44c172a7f6c9e
	FIND_PACKAGE_ARGS NAMES glfw3
	)
FetchContent_Declare(glm
	GIT_REPOSITORY https://github.com/g-truc/glm
	GIT_TAG	bf71a834948186f4097caa076cd2663c69a10e1e
	FIND_PACKAGE_ARGS NAMES glm)
FetchContent_MakeAvailable(glm glfw3)

add_executable(NEA src/main.cpp src/glad.c src/shader.cpp src/controls.cpp extern/imgui/backends/imgui_impl_glfw.cpp extern/imgui/backends/imgui_impl_opengl3.cpp extern/imgui/imgui.cpp extern/imgui/imgui_draw.cpp extern/imgui/imgui_tables.cpp extern/imgui/imgui_widgets.cpp)
target_include_directories(NEA PRIVATE include) 
include_directories("extern/imgui/")
file(
	GLOB ExternImGui
		"extern/imgui/*.cpp"
		"extern/imgui/*.h"
		)

target_link_libraries(NEA glfw imgui)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
file(COPY Shaders
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
