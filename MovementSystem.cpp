#include "MovementSystem.hpp"

MovementSystem::MovementSystem(float minX, float maxX, float minZ, float maxZ) :
	_minX(minX), _maxX(maxX), _minZ(minZ), _maxZ(maxZ)
{ }

glm::vec3 MovementSystem::updateBall(float delta, MovementState movement)
{
	glm::vec3 pos = movement.position + (movement.velocity * delta);
	return pos;
}
