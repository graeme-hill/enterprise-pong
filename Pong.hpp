#pragma once

#include "xe/Engine.hpp"
#include "generated/GameMessage.hpp"
#include "xe/Blob.hpp"
#include "PlayPong.hpp"
#include "MenuPong.hpp"
#include "Util.hpp"

enum class GameState
{
	Menu,
	Playing
};

class Pong
{
public:
	Pong(Engine &engine);
	void step(xe::Frame frame);

	void receiveBlob(xe::Blob blob);
	void onBounce(const msg::Bounce *message);
	void onGoal(const msg::Goal *message);
	void onPaddleGoLeft(const msg::PaddleGoLeft *message);
	void onPaddleGoRight(const msg::PaddleGoRight *message);
	void onPaddleStopLeft(const msg::PaddleStopLeft *message);
	void onPaddleStopRight(const msg::PaddleStopRight *message);
	void onChat(const msg::Chat *message);
	void onJoinRequest(const msg::JoinRequest *joinRequest);
	void onJoinResponse(const msg::JoinResponse *joinResponse);
	void onStart(const msg::Start *start);

private:
	Engine &_engine;
	GameState _gameState;
	PlayPong _play;
	MenuPong _menu;
};
