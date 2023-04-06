#version 330 core

layout (location = 0) in vec2 position;
uniform vec2 map_size;

void main() {
    vec2 cell_size = vec2(2.0 / map_size.x, 2.0 / map_size.y);
    gl_Position = vec4(
        position.x * cell_size.x,
        position.y * cell_size.y,
        0.0,
        1.0
    );
}