#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "controller.hpp"
#include "shader.hpp"

controller _controller;
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

GLuint lenght;
GLuint generate_mesh();
float cell_width = 100.0f, cell_height = 100.0f;
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

	cell_width = cell_width / WIN_WIDTH;
	cell_height = cell_height / WIN_HEIGHT;
	GLuint mesh = generate_mesh();
	shader _shader(
		"/home/cyril/Programming/snake/shader/mesh.vert",
		"/home/cyril/Programming/snake/shader/mesh.frag",
		"/home/cyril/Programming/snake/shader/mesh.geom"
	);

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		_controller.input_update();
		_controller.update();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(_shader.program);
		glUniform2f(glGetUniformLocation(_shader.program, "cell_size"), cell_width - 0.02, cell_height - 0.02);
	    glBindVertexArray(mesh);
	    glDrawArrays(GL_POINTS, 0, lenght);
        glBindVertexArray(0);

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

GLuint generate_mesh() {
	std::vector<glm::vec3> vertex;

	_controller._map._width = 2.0f / cell_width;
	_controller._map._height = 2.0f / cell_height;
	for (int j = 0; j < _controller._map._height; j++) {
    	for (int i = 0; i < _controller._map._width; i++) {
			GLfloat x = (float)i / (float)_controller._map._width;
			GLfloat y = (float)j / (float)_controller._map._height;
			vertex.push_back(glm::vec3(x * 2.0f - 1.0f, y * 2.0f - 1.0f, 0.0f));
		}
	}
	lenght = (GLuint)vertex.size();

	GLuint vbo, mesh;
	glGenVertexArrays(1, &mesh);
	glGenBuffers(1, &vbo);

	glBindVertexArray(mesh);


	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertex.size()*sizeof(glm::vec3), &vertex.front(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return mesh;
}