#include "Pong.hpp"

Pong::Pong(Window &window, Renderer &renderer) :
	_window(window),
	_renderer(renderer),
	_paddleMesh(Paddle::getMeshData()),
	_paddleMaterial(Paddle::getMaterial())
{
	std::cout << "Pong ctor\n";
}

void Pong::step(float delta)
{
	_renderer.setActiveMaterial(_paddleMaterial);
	_paddleMesh.render();
}
