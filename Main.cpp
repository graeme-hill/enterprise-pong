#include "Pong.hpp"
#include "xs/Server.hpp"

int main()
{
	xs::run();
	xe::play<Pong>();
}
