#pragma once

#include "Util.hpp"
#include "xr/MeshData.hpp"
#include <vector>

class Paddle
{
public:
	static xr::MeshData getMeshData();
	static Material getMaterial();
};
