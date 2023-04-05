#include "shader.hpp"

// Create shader program with vertex and fragment shader.
shader::shader(const std::string vertex_path, const std::string fragment_path, const std::string geometry_path) {
    GLuint shader_vertex = compile_shader_from_source(load_source_from_file(vertex_path), GL_VERTEX_SHADER);
    GLuint shader_fragment = compile_shader_from_source(load_source_from_file(fragment_path), GL_FRAGMENT_SHADER);
    GLuint shader_geometry;
    if (!geometry_path.empty()) {
    	shader_geometry = compile_shader_from_source(load_source_from_file(geometry_path), GL_GEOMETRY_SHADER);
    }
	this->program = glCreateProgram();
	glAttachShader(program, shader_vertex);
	glAttachShader(program, shader_fragment);
	if (!geometry_path.empty()) {
		glAttachShader(program, shader_geometry);
	}
	glLinkProgram(program);
	int success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if(!success) {
		char info_log[1024];
	    glGetProgramInfoLog(program, 512, NULL, info_log);
	    std::cout << "[ERROR::SHADER::PROGRAM::LINKING_FAILED]\n" << info_log << std::endl;
	}
	glDeleteShader(shader_vertex);
	glDeleteShader(shader_fragment);
}

// Load souce shader from file.
// Return source(std::string) shader.
std::string shader::load_source_from_file(const std::string &path) {
	std::string source;
	std::ifstream shader_file;
	shader_file.exceptions(std::ifstream::badbit);
	try {
		shader_file.open(path);
		std::stringstream shader_stream;
		shader_stream << shader_file.rdbuf();
		shader_file.close();
		source = shader_stream.str();
	}
	catch(std::ifstream::failure e) {
		std::cout << "[ERROR::SHADER::LOAD]\n\tFILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
	return source;
}

// Compile shader form source code.
// Return id(GLuint) shader.
GLuint shader::compile_shader_from_source(const std::string &source_str, const GLuint SHADER_TYPE) {
	GLuint shader = glCreateShader(SHADER_TYPE);
	const GLchar *source = source_str.c_str();
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success) {
		char info_log[1024];
	    glGetShaderInfoLog(shader, 512, NULL, info_log);
		std::cout << "[ERROR::SHADER::COMPILE]\n\t" << info_log << std::endl;
	};
	return shader;
}