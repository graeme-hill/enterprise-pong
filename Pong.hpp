#pragma once

#include "cr/glut/GlutPlatform.hpp"
#include "cg/Engine.hpp"

using Platform = cr::GlutPlatform;
using Window = typename Platform::Window;
using Renderer = typename Platform::Renderer;

class Pong
{
public:
	Pong(Window &window, Renderer &Renderer);
	void step(float delta);

private:
	Platform::Window &_window;
	Platform::Renderer &_renderer;
};
