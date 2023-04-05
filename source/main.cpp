#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "snake.hpp"
#include "food.hpp"

int WIN_WIDTH, WIN_HEIGHT;
int main() {
// Initialize.
	if (!glfwInit()) {
		std::cout << "[ERROR::GLFW::INIT]" << std::endl;
		return 0;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "[ERROR::GLFW::WINDOW] Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
	    std::cout << "[ERROR::GLFW::INIT] Failed to initialize GLEW" << std::endl;
	    return -1;
	}
	glfwGetFramebufferSize(window, &WIN_WIDTH, &WIN_HEIGHT);  
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	    glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}