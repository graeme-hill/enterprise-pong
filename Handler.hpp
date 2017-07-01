#pragma once

#include "flatbuffers/flatbuffers.h"

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
