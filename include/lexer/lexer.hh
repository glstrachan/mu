#pragma once

#include <string>

#include "lexer/lexutils.hh"
#include "lexer/lexid.hh"

struct lexer
{
	std::string source;
	std::string trivia;
	char current;
	int pos;
	int line;
	int linePos;

	lexer(std::string source);

	void step();
	lexToken token(tokenType type, std::string data);

	lexToken next();
	void eatTrivia();
	lexToken eatNumeric();
	lexToken eatString();
	lexToken eatSymbol();
	lexToken eatID();
};