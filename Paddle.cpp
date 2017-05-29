#include "Paddle.hpp"
#include "xe/File.hpp"

Paddle::Paddle() : _matrix(1.0f)
{ }

void Paddle::transform(std::function<glm::mat4(glm::mat4)> fn)
{
	_matrix = fn(_matrix);
}

xe::MeshData Paddle::getMeshData()
{
	float n = -0.5f;
	float p = 0.5f;

	std::vector<float> positions =
	{
		n, n, p,
		p, n, p,
		p, p, p,
		n, p, p,

		n, p, n,
		p, p, n,
		p, p, p,
		n, p, p,

		p, n, n,
		p, n, p,
		p, p, n,
		p, p, p,

		n, n, n,
		n, n, p,
		n, p, n,
		n, p, p,

		n, n, n,
		p, n, n,
		p, p, n,
		n, p, n,

		n, n, n,
		p, n, n,
		p, n, p,
		n, n, p,
	};

	std::vector<float> colors =
	{
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		1.0f, 0.5f, 0.0f,
		1.0f, 0.5f, 0.0f,
		1.0f, 0.5f, 0.0f,
		1.0f, 0.5f, 0.0f,

		0.8f, 0.0f, 0.8f,
		0.8f, 0.0f, 0.8f,
		0.8f, 0.0f, 0.8f,
		0.8f, 0.0f, 0.8f,

		0.4f, 1.0f, 1.0f,
		0.4f, 1.0f, 1.0f,
		0.4f, 1.0f, 1.0f,
		0.4f, 1.0f, 1.0f,

		0.4f, 0.6f, 0.6f,
		0.4f, 0.6f, 0.6f,
		0.4f, 0.6f, 0.6f,
		0.4f, 0.6f, 0.6f
	};

	std::vector<unsigned> indices =
	{
		0, 1, 2,
		0, 2, 3,

		4, 6, 5,
		4, 7, 6,

		8, 10, 9,
		9, 10, 11,

		12, 13, 14,
		13, 15, 14,

		16, 18, 17,
		16, 19, 18,

		20, 21, 22,
		20, 22, 23
	};

	std::vector<xe::VertexData> vertexData;
	vertexData.push_back(xe::VertexData(0, 3, positions));
	vertexData.push_back(xe::VertexData(1, 3, colors));
	xe::MeshData data(vertexData, indices);

	return data;
}
