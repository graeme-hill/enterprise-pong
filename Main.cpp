#include "Pong.hpp"
#include "xs/Server.hpp"

#include "generated/GameMessage_generated.h"

int main()
{
	flatbuffers::FlatBufferBuilder builder(1024);

	// capnp::MallocMessageBuilder message;
	// GameMessage::Builder msg = message.initRoot<GameMessage>();

	//xs::run();
	xe::play<Pong>();
}
