#version 100

precision mediump float;

uniform mat4 mvp;

attribute vec3 position;
attribute vec3 normal;

varying vec3 vColor;

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
