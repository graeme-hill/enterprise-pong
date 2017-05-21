#include "Pong.hpp"

Pong::Pong(Window &window, Renderer &renderer) :
	_window(window),
	_renderer(renderer)
{
	std::cout << "Pong ctor\n";
}

void Pong::step(float delta)
{
	std::cout << "step " << delta << std::endl;
}
