#include "Pong.hpp"
#include <glm/glm.hpp>
#include "xe/TKey.hpp"

Pong::Pong(Engine &engine) :
	_engine(engine),
	_paddleMesh(Paddle::getMeshData()),
	_standardMaterial("standard")
{
	std::cout << "Pong ctor\n";
}

void Pong::step(float delta)
{
	auto &renderer = _engine.renderer();
	auto &keyboard = _engine.keyboard();

	if (keyboard.isDown(xe::TKey::Left))
	{
		_camera.translate(delta * -0.01f, 0.0f);
	}
	else if (keyboard.isDown(xe::TKey::Right))
	{
		_camera.translate(delta * 0.01f, 0.0f);
	}

	renderer.setActiveShader(_standardMaterial.shader());
	glm::mat4 vp = _camera.viewProjection();
	glm::mat4 m(1.0f);
	_standardMaterial.mvp().set(vp * m);
	_paddleMesh.render();
}
