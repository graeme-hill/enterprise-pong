#pragma once

#include "xe/Engine.hpp"
#include "xe/Camera.hpp"
#include "xe/MeshData.hpp"
#include "Paddle.hpp"
#include "Court.hpp"
#include "Ball.hpp"
#include "Materials.hpp"
#include "MovementSystem.hpp"

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
	xe::TMesh _courtMesh;
	xe::TMesh _ballMesh;
	StandardMaterial _standardMaterial;
	CourtMaterial _courtMaterial;
	xe::Camera _camera;
	MovementSystem _movementSystem;

	Paddle _p1;
	Paddle _p2;
	Ball _ball;
};
