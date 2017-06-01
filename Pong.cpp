#include "Pong.hpp"
#include <glm/glm.hpp>
#include "xe/TKey.hpp"

Pong::Pong(Engine &engine) :
	_engine(engine),
	_paddleMesh(Paddle::getMeshData()),
	_courtMesh(Court::getMeshData()),
	_ballMesh(Ball::getMeshData()),
	_standardMaterial("standard"),
	_courtMaterial("court"),
	_ball({ -2.0f, 1.0f, 0.0f }),
	_movementSystem(-9.0f, 9.0f, -11.0f, 11.0f)
{
	std::cout << "Pong ctor\n";
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

	// camera

	glm::mat4 vp = _camera.viewProjection();

	// init shader

	renderer.setActiveShader(_standardMaterial.shader());

	// court

	_standardMaterial.mvp().set(vp * glm::mat4(1.0f));
	_courtMesh.render();

	// paddles

	_p1.setPosition({ 0.0f, 0.5f, -10.0f });
	_standardMaterial.mvp().set(vp * _p1.matrix());
	_paddleMesh.render();

	_p2.setPosition({ 0.0f, 0.5f, 10.0f });
	_standardMaterial.mvp().set(vp * _p2.matrix());
	_paddleMesh.render();

	// ball

	auto ballMatrix = glm::translate(glm::mat4(1.0f), _ball.position());
	_standardMaterial.mvp().set(vp * ballMatrix);
	_ballMesh.render();
}
