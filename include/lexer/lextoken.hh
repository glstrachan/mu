#pragma once

#include <string>
#include "lexer/lextokendata.hh"

struct lexToken
{
	tokenType type;
	std::string data;

	std::string trivia;
	int line;
	int pos;

	lexToken(tokenType type, std::string data, std::string trivia, int line, int pos);
};