#pragma once

#include <glm/glm.hpp>
#include "xe/MeshData.hpp"

class Ball
{
public:
	Ball(glm::vec3 position);
	glm::vec3 position() const { return _position; }

	static xe::MeshData getMeshData();

private:
	glm::vec3 _position;
};
