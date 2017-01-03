#pragma once

#include <string>
#include <vector>

class HuffmanEncoder {
public:
	static unsigned int encodeString(const std::string &input, std::vector<char>& encoding);
};

