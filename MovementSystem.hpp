#pragma once

#include "Components.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "glm/glm.hpp"

class MovementSystem
{
public:
	MovementSystem(float minX, float maxX, float minZ, float maxZ);
	void updateBall(float delta, Ball &ball, Paddle &p1, Paddle &p2);
	void updatePaddle(float delta, float dir, Paddle &paddle);

private:
	float _minX;
	float _maxX;
	float _minZ;
	float _maxZ;
};
