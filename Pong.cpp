#include "Pong.hpp"

Pong::Pong(Window &window, Renderer &renderer) :
	_window(window),
	_renderer(renderer),
	_paddleMesh(Paddle::getMeshData()),
	_standardMaterial("standard")
{
	std::cout << "Pong ctor\n";
}

void Pong::step(float delta)
{
	_renderer.setActiveShader(_standardMaterial.shader());
	_paddleMesh.render();
}
