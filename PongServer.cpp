#include "PongServer.hpp"

void join(const msg::JoinRequest *joinReq, xe::ServerDispatcher &dispatcher)
{
	auto join = dispatcher.join(payload->message_as_JoinRequest()->id());
	auto response = msg::CreateJoinResponsePayload(join.success, join.player);
	dispatcher.reply(response);
	if (join.player == 2)
	{
		dispatcher.broadcast(msg::CreateStartPayload());
	}
}

void PongServer::onMessage(xe::Blob blob, xe::ServerDispatcher &dispatcher)
{
	auto payload = msg::GetPayload(blob.dataPtr());
	auto type = payload->message_type();
	switch (type)
	{
	case msg::Message_JoinRequest:
		join(payload->message_as_JoinRequest());
		break;
	default:
		dispatcher.forward(blob);
		break;
	}
}
