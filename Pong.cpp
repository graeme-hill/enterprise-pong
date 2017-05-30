#include "Pong.hpp"
#include <glm/glm.hpp>
#include "xe/TKey.hpp"

Pong::Pong(Engine &engine) :
	_engine(engine),
	_paddleMesh(Paddle::getMeshData()),
	_courtMesh(Court::getMeshData()),
	_standardMaterial("standard"),
	_courtMaterial("court")
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

	// court

	renderer.setActiveShader(_courtMaterial.shader());
	_courtMaterial.mvp().set(vp * glm::mat4(1.0f));
	_courtMesh.render();

	// paddles

	renderer.setActiveShader(_standardMaterial.shader());

	_p1.transform([delta](glm::mat4 m)
	{
		return glm::rotate(m, delta * 0.003f, glm::vec3(0.0f, 1.0f, 0.0f));
	});

	_standardMaterial.mvp().set(vp * _p1.matrix());
	_paddleMesh.render();

	_p2.transform([delta](glm::mat4 m)
	{
		auto translated = glm::translate(m, glm::vec3(2.0f, 0.5f, 0.0f));
		auto rotated = glm::rotate(
			translated, delta * -0.003f, glm::vec3(0.0f, 0.0f, 1.0f));
		return rotated;
	});

	_standardMaterial.mvp().set(vp * _p2.matrix());
	_paddleMesh.render();

	_p2.transform([delta](glm::mat4 m)
	{
		auto translated = glm::translate(m, glm::vec3(-2.0f, -0.5f, 0.0f));
		return translated;
	});
}
