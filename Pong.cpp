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
	_ball({ -2.0f, 1.0f, 0.0f }, 0.5f)
{
	std::cout << "Pong ctor\n";
	_p1.setPosition({ 0.0f, 0.5f, -10.0f });
	_p2.setPosition({ 0.0f, 0.5f, 10.0f });
}

void Pong::step(float delta)
{
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

	if (keyboard.isDown(xe::TKey::Z))
	{
		_movementSystem.updatePaddle(delta, -1.0f, _p1);
	}
	if (keyboard.isDown(xe::TKey::C))
	{
		_movementSystem.updatePaddle(delta, 1.0f, _p1);
	}

	if (keyboard.isDown(xe::TKey::Comma))
	{
		_movementSystem.updatePaddle(delta, -1.0f, _p2);
	}
	if (keyboard.isDown(xe::TKey::Slash))
	{
		_movementSystem.updatePaddle(delta, 1.0f, _p2);
	}

	// movement

	_movementSystem.updateBall(delta, _ball, _p1, _p2);

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
