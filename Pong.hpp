#pragma once

#include "xe/Engine.hpp"
#include "xe/Camera.hpp"
#include "xe/MeshData.hpp"
#include "Paddle.hpp"
#include "Materials.hpp"

class Pong;

using Engine = xe::Engine<Pong>;

class Pong
{
public:
	Pong(Engine &engine);
	void step(float delta);

private:
	Engine &_engine;
	xe::TMesh _paddleMesh;
	StandardMaterial _standardMaterial;
	xe::Camera _camera;

	Paddle _p1;
};
