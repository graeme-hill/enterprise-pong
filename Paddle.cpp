#include "Paddle.hpp"
#include "xe/AssetReaders.hpp"
#include "xe/File.hpp"
#include <iostream>

Paddle::Paddle() : _matrix(1.0f)
{ }

void Paddle::setPosition(glm::vec3 position)
{
	_position = position;
	updateMatrix();
}

void Paddle::translate(glm::vec3 translation)
{
	_position += translation;
	updateMatrix();
}

glm::mat4 Paddle::matrix() const
{
	return _matrix;
}

void Paddle::updateMatrix()
{
	_matrix = glm::translate(glm::mat4(1.0f), _position);
}

xe::MeshData Paddle::getMeshData()
{
	xe::ModelData model = xe::readObjFileFlat("assets/paddle.obj");
	std::vector<xe::VertexData> vertexData;
	vertexData.push_back(xe::VertexData(0, 3, model.positions));
	vertexData.push_back(xe::VertexData(1, 3, model.normals));
	xe::MeshData data(vertexData, model.indices);
	return data;
}
