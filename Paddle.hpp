#pragma once

#include "xe/MeshData.hpp"
#include <vector>
#include <iostream>
#include <functional>
#include <glm/glm.hpp>

class Paddle
{
public:
	Paddle();
	void transform(std::function<glm::mat4(glm::mat4)> fn);
	glm::mat4 matrix() const { return _matrix; }

	static xe::MeshData getMeshData();

private:
	glm::mat4 _matrix;
};
