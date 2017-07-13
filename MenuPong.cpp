#include "MenuPong.hpp"
#include "Pong.hpp"

MenuPong::MenuPong(Engine &engine) : _engine(engine)
{ }

void MenuPong::step(xe::Frame frame)
{
	auto &keyboard = _engine.keyboard();

	if (keyboard.justReleased(xe::TKey::N1))
	{
		std::cout << "1\n";
		_engine.bus().post(msg::CreateJoinRequestPayload(1));
	}
	else if (keyboard.justReleased(xe::TKey::N2))
	{
		std::cout << "2\n";
		_engine.bus().post(msg::CreateJoinRequestPayload(2));
	}
	else if (keyboard.justReleased(xe::TKey::N3))
	{
		std::cout << "3\n";
		_engine.bus().post(msg::CreateJoinRequestPayload(3));
	}
}
