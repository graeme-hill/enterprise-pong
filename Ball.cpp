#include "Ball.hpp"
#include "xe/AssetReaders.hpp"

Ball::Ball(glm::vec3 position, float radius) :
	_movement{ position, glm::vec3(0.002f, 0.0f, 0.01f), radius }
{ }

void Ball::setPosition(glm::vec3 position)
{
	_movement.position = position;
}

void Ball::setVelocity(glm::vec3 velocity)
{
	_movement.velocity = velocity;
}

xe::MeshData Ball::getMeshData()
{
	xe::ModelData model = xe::readObjFileFlat("assets/ball.obj");
	std::vector<xe::VertexData> vertexData;
	vertexData.push_back(xe::VertexData(0, 3, model.positions));
	vertexData.push_back(xe::VertexData(1, 3, model.normals));
	xe::MeshData data(vertexData, model.indices);
	return data;
}
