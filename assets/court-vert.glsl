#version 300 es

precision mediump float;

uniform mat4 mvp;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 vColor;

void main()
{
    float yLight = (position.y + 2.0) / 3.0;
    float xLight = (position.x + 35.0) / 45.0;
    float zLight = (position.z + 37.0) / 49.0;
    float light = xLight * yLight * zLight;

    vColor = vec3(
        ((normal.x + 1.0) / 2.0) * light,
        ((normal.y + 1.0) / 2.0) * light,
        ((normal.z + 1.0) / 2.0) * light);
    gl_Position = mvp * vec4(position, 1.0);
}
