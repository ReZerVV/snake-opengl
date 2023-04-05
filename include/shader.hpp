#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

class shader
{
public:
	GLuint program;
    shader(const std::string vertex_path, const std::string fragment_path);
private:
    std::string load_source_from_file(const std::string &path);
    GLuint compile_shader_from_source(const std::string &source, const GLuint SHADER_TYPE);
};

#endif