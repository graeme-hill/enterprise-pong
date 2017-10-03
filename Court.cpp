#include "Court.hpp"
#include "xe/AssetReaders.hpp"

xe::MeshData Court::getMeshData()
{
	// xe::ModelData model = xe::readObjFileFlat("assets/court.obj");
	// std::vector<xe::VertexData> vertexData;
	// vertexData.push_back(xe::VertexData(0, 3, model.positions));
	// vertexData.push_back(xe::VertexData(1, 3, model.normals));
	// xe::MeshData data(vertexData, model.indices);
	// return data;

    xe::ModelData model = xe::readPlyFile("assets/tennis.ply");
    std::vector<xe::VertexData> vertexData;
    vertexData.push_back(xe::VertexData(0, 3, model.positions));
    vertexData.push_back(xe::VertexData(1, 3, model.normals));
    vertexData.push_back(xe::VertexData(2, 3, model.colors));
    xe::MeshData data(vertexData, model.indices);
    return data;
}
