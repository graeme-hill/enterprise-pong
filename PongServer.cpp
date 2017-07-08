#include "PongServer.hpp"
#include "generated/GameMessage.hpp"

void join(
	const msg::JoinRequest *joinReq, xe::SmallGroupServerDispatcher &dispatcher)
{
	auto join = dispatcher.joinGroup(joinReq->id());
	dispatcher.reply(msg::CreateJoinResponsePayload(join.success, join.player));
	if (join.player == 2)
	{
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
