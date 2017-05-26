#pragma once

#include "Util.hpp"
#include "xe/Engine.hpp"
#include "xe/Camera.hpp"
#include "xr/MeshData.hpp"
#include "Paddle.hpp"
#include "Materials.hpp"

class Pong
{
public:
	Pong(Window &window, Renderer &Renderer);
	void step(float delta);

private:
	Window &_window;
	Renderer &_renderer;
	Mesh _paddleMesh;
	StandardMaterial _standardMaterial;
	xe::Camera _camera;
};
