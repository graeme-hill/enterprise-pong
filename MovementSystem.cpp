#include "MovementSystem.hpp"
#include <cmath>
#include "xe/Math.hpp"
#include <iostream>

#define BIG_NUMBER 1000000.0f
#define ALMOST_ZERO 0.000001f
#define MAX_SPEED 0.03f
#define PADDLE_SPEED 0.015f
#define XISH 0.01f
#define ZISH 2.0f

xe::Intersection xBoundIntersect(
	glm::vec3 p, glm::vec3 v, float minX, float maxX)
{
	if (v.x > ALMOST_ZERO)
	{
		auto xDist = std::abs(p.x - maxX);
		auto zDist = (v.z / v.x) * xDist;
		return xe::Intersection::yes({ maxX, p.y, p.z + zDist });
	}
	else if (v.x < -ALMOST_ZERO)
	{
		auto xDist = std::abs(minX - p.x);
		auto zDist = (v.z / v.x) * xDist;
		return xe::Intersection::yes({ minX, p.y, p.z + zDist });
	}
	else
	{
		return xe::Intersection::no();
	}
}

xe::Intersection zBoundIntersect(
	glm::vec3 p, glm::vec3 v, float minZ, float maxZ)
{
	if (v.z > ALMOST_ZERO)
	{
		auto zDist = std::abs(p.z - maxZ);
		auto xDist = (v.x / v.z) * zDist;
		return xe::Intersection::yes({ p.x + xDist, p.y, maxZ });
	}
	else if (v.z < -ALMOST_ZERO)
	{
		auto zDist = std::abs(minZ - p.z);
		auto xDist = (v.x / v.z) * zDist;
		return xe::Intersection::yes({ p.x + xDist, p.y, minZ });
	}
	else
	{
		return xe::Intersection::no();
	}
}

bool inPaddleXZone(float x, Paddle &paddle)
{
	auto halfWidth = paddle.width() / 2.0f;
	auto paddleCenter = paddle.position();
	auto startX = paddleCenter.x - halfWidth - XISH;
	auto endX = paddleCenter.x + halfWidth + XISH;

	return startX <= x && x <= endX;
}

xe::Intersection paddleIntersect(
	glm::vec3 pos, glm::vec3 vel, Paddle &paddle, float r)
{
	if (std::abs(vel.z) < ALMOST_ZERO)
	{
		return xe::Intersection::no();
	}

	auto zLine = paddle.position().z + r;
	auto zTravel = zLine - pos.z;
	auto xTravel = zTravel * (vel.x / vel.z);
	auto intersectPoint = glm::vec3(pos.x + xTravel, pos.y, pos.z + zTravel);
	if (inPaddleXZone(intersectPoint.x, paddle))
	{
		return xe::Intersection::yes(intersectPoint);
	}
	else
	{
		return xe::Intersection::no();
	}
}

MovementSystem::MovementSystem(float minX, float maxX, float minZ, float maxZ) :
	_minX(minX), _maxX(maxX), _minZ(minZ), _maxZ(maxZ)
{ }

void MovementSystem::updateBall(float delta, Ball &ball, Paddle &p1, Paddle &p2)
{
	auto time = delta;
	auto movement = ball.movement();
	auto pos = movement.position;
	auto v = movement.velocity;
	auto r = movement.radius;

	while (true)
	{
		auto dest = pos + (v * time);
		auto destDist = glm::distance(pos, dest);

		auto paddleIntersection = v.z < 0.0f
			? paddleIntersect(pos, v, p1, 1.0f)
			: paddleIntersect(pos, v, p2, -1.0f);
		auto xIntersect = xBoundIntersect(pos, v, _minX + r, _maxX - r);
		auto zIntersect = zBoundIntersect(pos, v, _minZ + r, _maxZ - r);

		auto xDist = xIntersect.found
			? glm::distance(pos, xIntersect.point)
			: BIG_NUMBER;
		auto zDist = zIntersect.found
			? glm::distance(pos, zIntersect.point)
			: BIG_NUMBER;
		auto paddleDist = paddleIntersection.found
			? glm::distance(pos, paddleIntersection.point)
			: BIG_NUMBER;

		if (destDist <= xDist && destDist <= zDist && destDist <= paddleDist)
		{
			ball.setPosition(dest);
			ball.setVelocity(v);
			return;
		}

		if (xDist < zDist && xDist < paddleDist)
		{
			pos = xIntersect.point;
			time *= (xDist / destDist);
			v.x *= -1.0f;
		}
		else if (zDist < paddleDist)
		{
			pos = zIntersect.point;
			time *= (zDist / destDist);
			v.z *= -1.0f;
		}
		else
		{
			pos = paddleIntersection.point;
			time *= (paddleDist / destDist);
			v.z *= -1.0f;
		}

		if (glm::length(v) < MAX_SPEED)
		{
			v *= 1.1f;
		}
	}
}

void MovementSystem::updatePaddle(float delta, float dir, Paddle &paddle)
{
	auto xDiff = delta * dir * PADDLE_SPEED;
	paddle.translate(glm::vec3(xDiff, 0.0f, 0.0f));
}
