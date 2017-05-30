#version 300 es

precision mediump float;

uniform mat4 mvp;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 vColor;

void main()
{
    vColor = normal;
    gl_Position = mvp * vec4(position, 1.0);
}
