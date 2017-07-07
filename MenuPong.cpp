#include "MenuPong.hpp"
#include "Pong.hpp"

MenuPong::MenuPong(Engine &engine) : _engine(engine)
{ }

void MenuPong::step(xe::Frame frame)
{
	auto &keyboard = _engine.keyboard();

	if (keyboard.justReleased(xe::TKey::N1))
	{
		_engine.bus().post(msg::CreateJoinRequestPayload(1));
	}
	else if (keyboard.justReleased(xe::TKey::N2))
	{
		_engine.bus().post(msg::CreateJoinRequestPayload(2));
	}
	else if (keyboard.justReleased(xe::TKey::N3))
	{
		_engine.bus().post(msg::CreateJoinRequestPayload(3));
	}
}
