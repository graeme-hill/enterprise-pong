#pragma once

#include "Util.hpp"
#include "xe/Engine.hpp"
#include "xr/MeshData.hpp"
#include "Paddle.hpp"

class Pong
{
public:
	Pong(Window &window, Renderer &Renderer);
	void step(float delta);

private:
	Platform::Window &_window;
	Platform::Renderer &_renderer;
	Platform::Mesh _paddleMesh;
	Platform::Program _paddle
};
