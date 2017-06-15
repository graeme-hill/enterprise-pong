#include <string>
#include <iostream>
#include "Pong.hpp"
#include "xs/Server.hpp"
#include "xe/Backplane.hpp"
#include "generated/GameMessage.hpp"
#include "xs/WebSocketClient.hpp"

class Handler
{
public:
	template<typename T>
	void receive(T thing);

	void receiveBuffer(flatbuffers::DetachedBuffer const &buffer);
};

void Handler::receiveBuffer(flatbuffers::DetachedBuffer const &buffer)
{
	auto p = msg::GetPayload(buffer.data());
	p->message_receive(*this);
}

template <>
inline void Handler::receive(msg::Goal const *g)
{
	std::cout << "goal\n";
}

template <typename T>
inline void Handler::receive(T thing)
{
	std::cout << "unknown\n";
}

int main(int argc, char *argv[])
{
	std::string mode = argc > 1
		? argv[1]
		: "game";
	std::cout << "args: " << argc << std::endl;
	// xe::Backplane<msg::Payload, Handler> backplane;
	// flatbuffers::FlatBufferBuilder fbb(1024);
	//
	// auto p = msg::Vec3(0, 0, 0);
	// auto b = msg::CreateGoal(fbb, 0, 0, 0, &p);
	// auto po = msg::CreatePayload(fbb, msg::Message_Goal, b.Union());
	// fbb.Finish(po);
	// auto bp = fbb.ReleaseBufferPointer();
	//
	// backplane.post(std::move(bp));
	// Handler handler;
	//
	// std::cout << "1\n";
	// backplane.receive(handler);
	// std::cout << "2\n";
	// backplane.receive(handler);

	if (mode == "client")
	{
		std::cout << "startClient()\n";
		xs::startClient();
	}
	else if (mode == "server")
	{
		std::cout << "startServer()\n";
		xs::startServer();
	}
	else
	{
		xe::play<Pong>();
	}
}
