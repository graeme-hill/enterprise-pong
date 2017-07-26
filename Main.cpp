#include <string>
#include <iostream>
#include "Pong.hpp"
#include "generated/GameMessage.hpp"
#include "PongServer.hpp"
#include "xg/Guid.hpp"

#ifdef FEATURE_SERVER
#include "xe/GameServer.hpp"
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
		std::cout << xg::newGuid() << std::endl;
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
