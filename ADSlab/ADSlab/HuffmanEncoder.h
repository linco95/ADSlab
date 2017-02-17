#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class HuffmanEncoder {
public:
	static unsigned int encodeString(const std::string &input, std::unordered_map<char, std::string>& charCodes);
};

