#pragma once

#include "xr/glut/GlutPlatform.hpp"
#include "xe/Engine.hpp"
#include "xr/MeshData.hpp"
#include "Paddle.hpp"

using Platform = xr::GlutPlatform;
using Window = typename Platform::Window;
using Renderer = typename Platform::Renderer;

class Pong
{
public:
	Pong(Window &window, Renderer &Renderer);
	void step(float delta);

private:
	Platform::Window &_window;
	Platform::Renderer &_renderer;
	Platform::Mesh _paddleMesh;
};
