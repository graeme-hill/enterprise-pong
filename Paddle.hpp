#pragma once

#include "xe/MeshData.hpp"
#include <vector>
#include <iostream>
#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Paddle
{
public:
	Paddle();
	void setPosition(glm::vec3 position);
	void translate(glm::vec3 translation);
	glm::mat4 matrix() const;

	static xe::MeshData getMeshData();

private:
	void updateMatrix();

	glm::vec3 _position;
	glm::mat4 _matrix;
};
