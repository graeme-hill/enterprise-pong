#include "Pong.hpp"
#include "glm/glm.hpp"
#include "xe/TKey.hpp"

Pong::Pong(Engine &engine) :
	_engine(engine),
	_paddleMesh(Paddle::getMeshData()),
	_courtMesh(Court::getMeshData()),
	_ballMesh(Ball::getMeshData()),
	_standardMaterial("standard"),
	_courtMaterial("court"),
	_movementSystem(-9.0f, 9.0f, -11.0f, 11.0f),
	_ball({ -2.0f, 1.0f, 0.0f }, 0.5f),
	_paddles{ &_p1, &_p2 }
{
	_p1.setPosition({ 0.0f, 0.5f, -10.0f });
	_p2.setPosition({ 0.0f, 0.5f, 10.0f });
	_engine.bus().connect("ws://localhost:9002");
}

void Pong::step(xe::Frame frame)
{
	auto delta = frame.delta;
	auto &renderer = _engine.renderer();
	auto &keyboard = _engine.keyboard();

	// input

	if (keyboard.isDown(xe::TKey::A))
	{
		_camera.translate(delta * -0.01f, 0.0f);
	}
	if (keyboard.isDown(xe::TKey::D))
	{
		_camera.translate(delta * 0.01f, 0.0f);
	}
	if (keyboard.isDown(xe::TKey::S))
	{
		_camera.translate(0.0f, delta * 0.01f);
	}
	if (keyboard.isDown(xe::TKey::W))
	{
		_camera.translate(0.0f, delta * -0.01f);
	}
	if (keyboard.isDown(xe::TKey::Space))
	{
		_camera.zoom(delta * 0.01f);
	}
	if (keyboard.isDown(xe::TKey::LShift))
	{
		_camera.zoom(delta * -0.01f);
	}

	if (keyboard.justPressed(xe::TKey::Z))
	{
		// flatbuffers::FlatBufferBuilder fbb(1024);
		_engine.bus().post(msg::CreatePaddleGoLeftPayload(
			frame.elapsed,
			1,
			msg::SpaceTime(msg::Vec3(0.0f, 0.0f, 0.0f), 2)));
		//_movementSystem.updatePaddle(delta, -1.0f, _p1);
	}
	else if (keyboard.justReleased(xe::TKey::Z))
	{
		// flatbuffers::FlatBufferBuilder fbb(1024);
		_engine.bus().post(msg::CreatePaddleStopLeftPayload(
			frame.elapsed,
			1,
			msg::SpaceTime(msg::Vec3(0.0f, 0.0f, 0.0f), 2)));
		//_movementSystem.updatePaddle(delta, -1.0f, _p1);
	}

	if (keyboard.justPressed(xe::TKey::C))
	{
		_engine.bus().post(msg::CreatePaddleGoRightPayload(
			frame.elapsed,
			1,
			msg::SpaceTime(msg::Vec3(0.0f, 0.0f, 0.0f), 2)));
		//_movementSystem.updatePaddle(delta, 1.0f, _p1);
	}
	else if (keyboard.justReleased(xe::TKey::C))
	{
		_engine.bus().post(msg::CreatePaddleStopRightPayload(
			frame.elapsed,
			1,
			msg::SpaceTime(msg::Vec3(0.0f, 0.0f, 0.0f), 2)));
		//_movementSystem.updatePaddle(delta, 1.0f, _p1);
	}

	if (keyboard.justPressed(xe::TKey::Comma))
	{
		_engine.bus().post(msg::CreatePaddleGoLeftPayload(
			frame.elapsed,
			2,
			msg::SpaceTime(msg::Vec3(0.0f, 0.0f, 0.0f), 2)));
	}
	else if (keyboard.justReleased(xe::TKey::Comma))
	{
		_engine.bus().post(msg::CreatePaddleStopLeftPayload(
			frame.elapsed,
			2,
			msg::SpaceTime(msg::Vec3(0.0f, 0.0f, 0.0f), 2)));
		//_movementSystem.updatePaddle(delta, -1.0f, _p2);
	}

	if (keyboard.justPressed(xe::TKey::Slash))
	{
		_engine.bus().post(msg::CreatePaddleGoRightPayload(
			frame.elapsed,
			2,
			msg::SpaceTime(msg::Vec3(0.0f, 0.0f, 0.0f), 2)));
		//_movementSystem.updatePaddle(delta, 1.0f, _p2);
	}
	else if (keyboard.justReleased(xe::TKey::Slash))
	{
		_engine.bus().post(msg::CreatePaddleStopRightPayload(
			frame.elapsed,
			2,
			msg::SpaceTime(msg::Vec3(0.0f, 0.0f, 0.0f), 2)));
		//_movementSystem.updatePaddle(delta, 1.0f, _p2);
	}

	_engine.bus().receive(*this);

	// movement

	_movementSystem.updateBall(delta, _ball, _p1, _p2);

	if (_p1.goingLeft())
	{
		_movementSystem.updatePaddle(delta, -1.0f, _p1);
	}
	if (_p1.goingRight())
	{
		_movementSystem.updatePaddle(delta, 1.0f, _p1);
	}

	// camera

	glm::mat4 vp = _camera.viewProjection();

	// init shader

	renderer.setActiveShader(_standardMaterial.shader());

	// court

	_standardMaterial.mvp().set(vp * glm::mat4(1.0f));
	_courtMesh.render();

	// paddles

	_standardMaterial.mvp().set(vp * _p1.matrix());
	_paddleMesh.render();

	_standardMaterial.mvp().set(vp * _p2.matrix());
	_paddleMesh.render();

	// ball

	auto ballMatrix = glm::translate(glm::mat4(1.0f), _ball.movement().position);
	_standardMaterial.mvp().set(vp * ballMatrix);
	_ballMesh.render();
}

void Pong::receiveBlob(xe::Blob blob)
{
	auto p = msg::GetPayload(blob.dataPtr());
	p->message_receive(*this);
}

void Pong::onBounce(const msg::Bounce *message)
{
	std::cout << "onBounce\n";
}

void Pong::onGoal(const msg::Goal *message)
{
	std::cout << "onGoal\n";
}

void Pong::onPaddleGoLeft(const msg::PaddleGoLeft *message)
{
	getPaddle(message->player())->goingLeft(true);
}

void Pong::onPaddleGoRight(const msg::PaddleGoRight *message)
{
	getPaddle(message->player())->goingRight(true);
}

void Pong::onPaddleStopLeft(const msg::PaddleStopLeft *message)
{
	getPaddle(message->player())->goingLeft(false);
}

void Pong::onPaddleStopRight(const msg::PaddleStopRight *message)
{
	getPaddle(message->player())->goingRight(false);
}

void Pong::onChat(const msg::Chat *message)
{
	std::cout << "onChat\n";
}

Paddle *Pong::getPaddle(unsigned player)
{
	return _paddles.at((player - 1) % _paddles.size());
}
