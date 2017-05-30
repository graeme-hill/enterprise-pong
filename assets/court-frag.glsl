#version 300 es

precision mediump float;

out vec4 color;

in vec3 vColor;

void main()
{
    color = vec4(vColor, 1.0f);
}
