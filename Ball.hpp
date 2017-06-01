#pragma once

#include <glm/glm.hpp>
#include "xe/MeshData.hpp"
#include "Components.hpp"

class Ball
{
public:
	Ball(glm::vec3 position, float radius);
	MovementState movement() const { return _movement; }
	void setPosition(glm::vec3 position);

	static xe::MeshData getMeshData();

private:
	MovementState _movement;
};
