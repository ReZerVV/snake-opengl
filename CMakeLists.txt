cmake_minimum_required(VERSION 3.0.0)
project(snake VERSION 0.1.0 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)

add_executable(snake
	source/main.cpp
	source/snake.cpp
	source/food.cpp
	source/map.cpp
	source/controller.cpp
)

find_package(OpenGL REQUIRED)
find_package(GLEW 2.0 REQUIRED)
find_package(glm REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

include_directories(
	include/
	${OPENGL_INCLUDE_DIRS}
	${GLEW_INCLUDE_DIRS}
	${GLFW_INCLUDE_DIRS}
	${GLM_INCLUDE_DIRS}
)

target_link_libraries(snake
	OpenGL::GL
	GLEW::GLEW
	${GLFW_LIBRARIES}
	${GML_LIBRARIES}
	X11
	Xrandr
	Xi
)