#include "Pong.hpp"
#include <glm/glm.hpp>

Pong::Pong(P::Window &window, P::Renderer &renderer) :
	_window(window),
	_renderer(renderer),
	_paddleMesh(Paddle::getMeshData()),
	_standardMaterial("standard")
{
	std::cout << "Pong ctor\n";
}

void Pong::step(float delta)
{
	_camera.translate(delta * 0.01f, 0.0f);
	_renderer.setActiveShader(_standardMaterial.shader());
	glm::mat4 vp = _camera.viewProjection();
	glm::mat4 m(1.0f);
	_standardMaterial.mvp().set(vp * m);
	_paddleMesh.render();
}
