#pragma once
#include <string>
#include <sstream>
class Converters
{
public:
	static Uint32 IntToHex(int value);
};

Uint32 Converters::IntToHex(int value)
{
	unsigned int x;
	std::stringstream ss;
	ss << std::hex << value;
	ss >> x;
	return x;
}