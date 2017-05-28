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
	Pong(P::Window &window, P::Renderer &Renderer);
	void step(float delta);

private:
	P::Window &_window;
	P::Renderer &_renderer;
	P::Mesh _paddleMesh;
	StandardMaterial _standardMaterial;
	xe::Camera _camera;
};
