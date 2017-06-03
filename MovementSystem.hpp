#pragma once

#include "Components.hpp"
#include "Ball.hpp"
#include <glm/glm.hpp>

class MovementSystem
{
public:
	MovementSystem(float minX, float maxX, float minZ, float maxZ);
	void updateBall(float delta, Ball &ball);

private:
	float _minX;
	float _maxX;
	float _minZ;
	float _maxZ;
};
