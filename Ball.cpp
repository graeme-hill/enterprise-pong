#include "Ball.hpp"
#include "xe/AssetReaders.hpp"

Ball::Ball(glm::vec3 position) : _position(position)
{ }

xe::MeshData Ball::getMeshData()
{
	xe::ModelData model = xe::readObjFileFlat("assets/ball.obj");
	std::vector<xe::VertexData> vertexData;
	vertexData.push_back(xe::VertexData(0, 3, model.positions));
	vertexData.push_back(xe::VertexData(1, 3, model.normals));
	xe::MeshData data(vertexData, model.indices);
	return data;
}
