#include "Paddle.hpp"
#include "xe/File.hpp"

xe::MeshData Paddle::getMeshData()
{
	std::vector<float> positions =
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	std::vector<unsigned> indices =
	{
		0, 2, 1
	};

	std::vector<xe::VertexData> vertexData;
	vertexData.push_back(xe::VertexData(0, 3, positions));
	xe::MeshData data(vertexData, indices);

	return data;
}
