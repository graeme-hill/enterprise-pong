#pragma once

#include "Components.hpp"
#include <glm/glm.hpp>

class MovementSystem
{
public:
	MovementSystem(float minX, float maxX, float minZ, float maxZ);
	glm::vec3 updateBall(float delta, MovementState movement);

private:
	float _minX;
	float _maxX;
	float _minZ;
	float _maxZ;
};
