#pragma once

#include "xe/Engine.hpp"
#include "Util.hpp"

class MenuPong
{
public:
	MenuPong(Engine &engine);
	void step(xe::Frame frame);

private:
	Engine &_engine;
};
