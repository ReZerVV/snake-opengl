#version 330 core

layout (points) in;
layout (line_strip, max_vertices = 5) out;

uniform vec2 cell_size;

void main() {    
    gl_Position = gl_in[0].gl_Position + vec4(0.01, 0.01, 0.0, 0.0);
    EmitVertex();

    gl_Position = gl_in[0].gl_Position + vec4(0.01 + cell_size.x, 0.01, 0.0, 0.0); 
    EmitVertex();

    gl_Position = gl_in[0].gl_Position + vec4(0.01 + cell_size.x, 0.01 + cell_size.y, 0.0, 0.0); 
    EmitVertex();

    gl_Position = gl_in[0].gl_Position + vec4(0.01, 0.01 + cell_size.y, 0.0, 0.0); 
    EmitVertex();

    gl_Position = gl_in[0].gl_Position + vec4(0.01, 0.01, 0.0, 0.0); 
    EmitVertex();

    EndPrimitive();
} 