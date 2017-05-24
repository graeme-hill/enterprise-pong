#include "Paddle.hpp"
#include "xe/File.hpp"

xr::MeshData Paddle::getMeshData()
{
	std::vector<float> positions =
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	std::vector<unsigned> indices =
	{
		0, 1, 2,
		1, 2, 3
	};

	std::vector<xr::VertexData> vertexData;
	vertexData.push_back(xr::VertexData(0, 3, positions));
	xr::MeshData data(vertexData, indices);
	return data;
}

Material Paddle::getMaterial()
{
	std::string vert = xe::File::readAll("assets/vert.glsl");
	std::string frag = xe::File::readAll("assets/frag.glsl");
	return Material(vert, frag);
}
