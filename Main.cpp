#include <string>
#include <iostream>
#include "Pong.hpp"
#include "generated/GameMessage.hpp"
#include "PongServer.hpp"
#include "xe/GameServer.hpp"
#include "xe/SmallGroupWebSocketConfig.hpp"

#include "xe/WebSocketClient.hpp"
#include "xe/WebSocketServer.hpp"

int main(int argc, char *argv[])
{
	std::string mode = argc > 1
		? argv[1]
		: "game";

	if (mode == "server")
	{
		xe::serve<xe::SmallGroupWebSocketConfig<PongServer>>(9002);
	}
	else
	{
		xe::play<Pong>();
	}
}
