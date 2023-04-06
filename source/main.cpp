#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "map.hpp"
#include "controller.hpp"
#include "shader.hpp"

map _map(20, 20);
snake _snake;
controller _controller(&_map, &_snake);

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
GLuint generate_cell();

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
	GLFWwindow* window = glfwCreateWindow(800, 800, "LearnOpenGL", nullptr, nullptr);
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
	
	shader shader_snake (
		"/home/cyril/Programming/snake/shader/snake_vert.glsl",
		"/home/cyril/Programming/snake/shader/snake_frag.glsl"
	);

	GLuint cell = generate_cell();
	GLfloat time_now = glfwGetTime();
	GLfloat time_last = glfwGetTime();
	GLfloat delta_time = 0.0f, time_sum = 0.0f;
	while(!glfwWindowShouldClose(window)) {
		
		time_now = glfwGetTime();
		delta_time = time_now - time_last;
		time_last = time_now;
		time_sum += delta_time;
		glfwPollEvents();
		if (time_sum >= 1.0f / 16) {
			time_sum = 0.0f;
			_controller.input_update();
			_controller.update();
		}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(cell);
			glUseProgram(shader_snake.program);
			glUniform2f(
				glGetUniformLocation(shader_snake.program, "map_size"),
				_map._width,
				_map._height
			);
			for (int i = 0; i < _snake._body.size(); ++i) {
				glUniform3f(
					glGetUniformLocation(shader_snake.program, "color"),
					0.0f, 1.0f, 0.5f
				);
				glUniform2fv(
					glGetUniformLocation(shader_snake.program, "position"),
					1,
					glm::value_ptr(_snake._body[i])
				);
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
			}
			glUniform3f(
				glGetUniformLocation(shader_snake.program, "color"),
				1.0f, 0.0f, 0.5f
			);
			glUniform2fv(
				glGetUniformLocation(shader_snake.program, "position"),
				1,
				glm::value_ptr(_controller._food._position)
				//glm::value_ptr(glm::vec2(50, 50))
			);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
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

// Generate cell.
GLuint generate_cell() {
	GLfloat vertices[] = {
		0.0, 0.0,
		0.0, 1.0,
		1.0, 1.0,
		1.0, 0.0
	};
	GLuint indices[] = {
	  	0, 1, 2,
  		2, 3, 0
	};

	GLuint vbo, ebo, cell;

	glGenVertexArrays(1, &cell);
	glBindVertexArray(cell);
	
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// end

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// end
	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*2, (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return cell;
}