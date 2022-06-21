#pragma once

#include <string>

struct lexToken
{
	tokenType type;
	std::string data;

	std::string trivia;
	int line;
	int start;
	int end;

	lexToken(tokenType type, std::string data, std::string trivia, int line, int start, int end);
};