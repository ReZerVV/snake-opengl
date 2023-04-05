#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "controller.hpp"

controller _controller;
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

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
	glfwSetKeyCallback(window, key_callback);

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		_controller.input_update();
		_controller.update();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	    glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS) {
        	std::cout << "[KEY::PRESS] --> " << key << ":" << (char)key << std::endl; 
            _controller._keys[key] = true;
        }
        else if (action == GLFW_RELEASE) {
        	std::cout << "[KEY::RELEASE] --> " << key << ":" << (char)key << std::endl; 
            _controller._keys[key] = false;
        }
    }
}
