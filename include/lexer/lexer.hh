#pragma once

#include <string>

#include "lexid.hh"
#include "lextoken.hh"

struct lexer
{
	std::string source;
	std::string trivia;
	char at;
	int pos;
	int line;
	int linePos;

	lexer(std::string source);

	void advance();
	lexToken token(tokenType type, std::string data);

	lexToken next();
	lexToken eatTrivia();
	lexToken eatNumeric();
	lexToken eatString();
	lexToken eatSymbol();
	lexToken eatID();
};