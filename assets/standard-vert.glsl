#version 300 es

precision mediump float;

uniform mat4 mvp;

layout (location = 0) in vec3 position;

void main()
{
    gl_Position = mvp * vec4(position, 1.0);
}
