#pragma once

#include "xe/Blob.hpp"
#include "xe/SmallGroupServerDispatcher.hpp"

class PongServer
{
public:
	void onMessage(xe::Blob blob, xe::SmallGroupServerDispatcher &dispatcher);
};
