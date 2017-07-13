#include <string>
#include <iostream>
#include "Pong.hpp"
#include "generated/GameMessage.hpp"
#include "PongServer.hpp"

#ifdef FEATURE_SERVER
#include "xe/GameServerddd.hpp"
#include "xe/SmallGroupWebSocketConfig.hpp"
#endif

int main(int argc, char *argv[])
{
	std::string mode = argc > 1
		? argv[1]
		: "game";

	if (mode == "server")
	{
		#ifdef FEATURE_SERVER
		xe::serve<xe::SmallGroupWebSocketConfig<PongServer>>(9002);
		#else
		std::cout << "Server is not enabled in this build. Good bye.\n";
		#endif
	}
	else
	{
		xe::play<Pong>();
	}
}
