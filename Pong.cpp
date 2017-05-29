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

	_p1.transform([delta](glm::mat4 m)
	{
		return glm::rotate(m, delta * 0.003f, glm::vec3(0.0f, 1.0f, 0.0f));
	});

	_standardMaterial.mvp().set(vp * _p1.matrix());
	_paddleMesh.render();

	_p2.transform([delta](glm::mat4 m)
	{
		auto translated = glm::translate(m, glm::vec3(2.0f, 0.0f, 0.0f));
		auto rotated = glm::rotate(
			translated, delta * -0.003f, glm::vec3(0.0f, 0.0f, 1.0f));
		return rotated;
	});

	_standardMaterial.mvp().set(vp * _p2.matrix());
	_paddleMesh.render();

	_p2.transform([delta](glm::mat4 m)
	{
		auto translated = glm::translate(m, glm::vec3(-2.0f, 0.0f, 0.0f));
		return translated;
	});
}
