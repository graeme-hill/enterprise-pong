#pragma once

#include "xe/Engine.hpp"
#include "xe/Camera.hpp"
#include "xe/MeshData.hpp"
#include "Paddle.hpp"
#include "Materials.hpp"

class Pong
{
public:
	Pong(xe::TWindow &window, xe::TRenderer &renderer);
	void step(float delta);

private:
	xe::TWindow &_window;
	xe::TRenderer &_renderer;
	xe::TMesh _paddleMesh;
	StandardMaterial _standardMaterial;
	xe::Camera _camera;
};
