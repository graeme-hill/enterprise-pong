#pragma once

#include "xe/Engine.hpp"
#include "xe/Camera.hpp"
#include "xe/MeshData.hpp"
#include "xe/WebSocketClient.hpp"
#include "Paddle.hpp"
#include "Court.hpp"
#include "Ball.hpp"
#include "Materials.hpp"
#include "MovementSystem.hpp"
#include "generated/GameMessage.hpp"
#include "xe/Blob.hpp"

class Pong;

using Engine = xe::Engine<Pong>;

class Pong
{
public:
	Pong(Engine &engine);
	void step(xe::Frame frame);

	void receiveBlob(xe::Blob blob);
	void onBounce(const msg::Bounce *message);
	void onGoal(const msg::Goal *message);
	void onPaddleGoLeft(const msg::PaddleGoLeft *message);
	void onPaddleGoRight(const msg::PaddleGoRight *message);
	void onPaddleStopLeft(const msg::PaddleStopLeft *message);
	void onPaddleStopRight(const msg::PaddleStopRight *message);
	void onChat(const msg::Chat *message);

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
