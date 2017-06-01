#pragma once

#include <glm/glm.hpp>
#include "xe/MeshData.hpp"
#include "Components.hpp"

class Ball
{
public:
	Ball(glm::vec3 position);
	MovementState movement() const { return _movement; }
	void setPosition(glm::vec3 position);

	static xe::MeshData getMeshData();

private:
	MovementState movementFromPosition();
	MovementState _movement;
};
