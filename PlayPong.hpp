#pragma once

#include "xe/Engine.hpp"
#include "xe/Camera.hpp"
#include "xe/MeshData.hpp"
#include "Paddle.hpp"
#include "Court.hpp"
#include "Ball.hpp"
#include "Materials.hpp"
#include "MovementSystem.hpp"
#include "Util.hpp"

class PlayPong
{
public:
	PlayPong(Engine &engine);
	Paddle *getPaddle(unsigned player);
	void step(xe::Frame frame);

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
	std::vector<Paddle *> _paddles;
};
