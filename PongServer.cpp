#include "PongServer.hpp"
#include "generated/GameMessage.hpp"
#include <iostream>

void join(
	const msg::JoinRequest *joinReq, xe::SmallGroupServerDispatcher &dispatcher)
{
	std::cout << "!!! JOIN !!!\n";
	auto join = dispatcher.joinGroup(joinReq->id());
	dispatcher.reply(msg::CreateJoinResponsePayload(join.success, join.player));
	std::cout << "player " << join.player << std::endl;
	if (join.player == 2)
	{
		std::cout << "!!! START !!!\n";
		dispatcher.broadcast(msg::CreateStartPayload());
	}
}

void PongServer::onMessage(
	xe::Blob blob, xe::SmallGroupServerDispatcher &dispatcher)
{
	auto payload = msg::GetPayload(blob.dataPtr());
	auto type = payload->message_type();
	switch (type)
	{
	case msg::Message_JoinRequest:
		join(payload->message_as_JoinRequest(), dispatcher);
		break;
	default:
		dispatcher.forward(blob);
		break;
	}
}
