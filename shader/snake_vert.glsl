#version 330 core

layout (location = 0) in vec2 v_position;

uniform vec2 position;
uniform vec2 map_size;

void main() {
    vec2 cell_size = vec2(2.0 / map_size.x, 2.0 / map_size.y);
    vec2 position_center = vec2(
        (position.x * cell_size.x) - 1.0 - (cell_size.x / 2),
        1.0 - (cell_size.y / 2) - (position.y * cell_size.y)
    );
    gl_Position = vec4(
        position_center.x - (cell_size.x / 2) + (v_position.x * cell_size.x),
        position_center.y - (cell_size.y / 2) + (v_position.y * cell_size.y),
        0.0,
        1.0
    );
}