#include "Pong.hpp"
#include "glm/glm.hpp"
#include "xe/TKey.hpp"

Pong::Pong(Engine &engine) :
	_engine(engine),
	_gameState(GameState::Menu),
	_play(engine),
	_menu(engine)
{
	_engine.bus().connect("ws://localhost:9002");
}

void Pong::step(xe::Frame frame)
{
	switch (_gameState)
	{
	case GameState::Menu:
		_menu.step(frame);
		_engine.bus().receive(*this);
		// _engine.bus().receiveIf(*this, [](const xe::Blob &blob) -> bool
		// {
		// 	auto p = msg::GetPayload(blob.dataPtr());
		// 	return p->message_type() == msg::Message_Start;
		// });
		break;
	case GameState::Playing:
		_play.step(frame);
		_engine.bus().receive(*this);
		break;
	default:
		break;
	}
}

void Pong::receiveBlob(xe::Blob blob)
{
	auto p = msg::GetPayload(blob.dataPtr());
	std::cout << "INCOMING BLOB type: " << p->message_type() << std::endl;
	p->message_receive(*this);
}

void Pong::onBounce(const msg::Bounce *message)
{
	std::cout << "onBounce\n";
}

void Pong::onGoal(const msg::Goal *message)
{
	std::cout << "onGoal\n";
}

void Pong::onPaddleGoLeft(const msg::PaddleGoLeft *message)
{
	_play.getPaddle(message->player())->goingLeft(true);
}

void Pong::onPaddleGoRight(const msg::PaddleGoRight *message)
{
	_play.getPaddle(message->player())->goingRight(true);
}

void Pong::onPaddleStopLeft(const msg::PaddleStopLeft *message)
{
	_play.getPaddle(message->player())->goingLeft(false);
}

void Pong::onPaddleStopRight(const msg::PaddleStopRight *message)
{
	_play.getPaddle(message->player())->goingRight(false);
}

void Pong::onChat(const msg::Chat *message)
{
	std::cout << "onChat\n";
}

void Pong::onJoinRequest(const msg::JoinRequest *joinRequest)
{
	std::cout << "onJoinRequest\n";
}

void Pong::onJoinResponse(const msg::JoinResponse *joinResponse)
{
	std::cout << "onJoinResponse\n";
}

void Pong::onStart(const msg::Start *start)
{
	_gameState = GameState::Playing;
	std::cout << "onStart\n";
}
