#include "MovementSystem.hpp"
#include <cmath>
#include "xe/Math.hpp"
#include <iostream>

#define BIG_NUMBER 1000000.0f
#define ALMOST_ZERO 0.000001f
#define MAX_SPEED 0.05f

xe::Intersection xBoundIntersect(
	glm::vec3 p, glm::vec3 v, float minX, float maxX)
{
	if (v.x > ALMOST_ZERO)
	{
		auto xDist = std::abs(p.x - maxX);
		auto zDist = (v.z / v.x) * xDist;
		return { true, { maxX, p.y, p.z + zDist } };
	}
	else if (v.x < -ALMOST_ZERO)
	{
		auto xDist = std::abs(minX - p.x);
		auto zDist = (v.z / v.x) * xDist;
		return { true, { minX, p.y, p.z + zDist } };
	}
	else
	{
		return { false, glm::vec3(0.0f) };
	}
}

xe::Intersection zBoundIntersect(
	glm::vec3 p, glm::vec3 v, float minZ, float maxZ)
{
	if (v.z > ALMOST_ZERO)
	{
		auto zDist = std::abs(p.z - maxZ);
		auto xDist = (v.x / v.z) * zDist;
		return { true, { p.x + xDist, p.y, maxZ } };
	}
	else if (v.z < -ALMOST_ZERO)
	{
		auto zDist = std::abs(minZ - p.z);
		auto xDist = (v.x / v.z) * zDist;
		return { true, { p.x + xDist, p.y, minZ } };
	}
	else
	{
		return { false, glm::vec3(0.0f) };
	}
}

MovementSystem::MovementSystem(float minX, float maxX, float minZ, float maxZ) :
	_minX(minX), _maxX(maxX), _minZ(minZ), _maxZ(maxZ)
{ }

void MovementSystem::updateBall(float delta, Ball &ball)
{
	auto time = delta;
	auto movement = ball.movement();
	auto pos = movement.position;
	auto v = movement.velocity;
	auto r = movement.radius;

	while (true)
	{
		auto dest = pos + (v * time);

		auto xIntersect = xBoundIntersect(pos, v, _minX + r, _maxX - r);
		auto zIntersect = zBoundIntersect(pos, v, _minZ + r, _maxZ - r);

		auto destDist = glm::distance(pos, dest);
		auto xDist = xIntersect.found
			? glm::distance(pos, xIntersect.point)
			: BIG_NUMBER;
		auto zDist = zIntersect.found
			? glm::distance(pos, zIntersect.point)
			: BIG_NUMBER;

		if (destDist <= xDist && destDist <= zDist)
		{
			ball.setPosition(dest);
			ball.setVelocity(v);
			return;
		}

		if (xDist < zDist)
		{
			pos = xIntersect.point;
			time *= (xDist / destDist);
			v.x *= -1.0f;
		}
		else
		{
			pos = zIntersect.point;
			time *= (zDist / destDist);
			v.z *= -1.0f;
		}

		if (glm::length(v) < MAX_SPEED)
		{
			v *= 1.1f;
		}
	}
}
