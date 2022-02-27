#include "lexer/lexer.hh"

#include <ctype.h>

lexer::lexer(std::string source) : 
source(source), trivia(""), at(source[0]), pos(0), line(0), linePos(0) {}

void lexer::advance()
{
	if(current != EOF) 
	{
		pos++;
		current = source[pos];
	}
}

lexToken lexer::token(tokenType type, std::string data)
{
	return new lexToken(type, data, trivia, line, linePos);
}

lexToken lexer::next()
{
	while(current != EOF)
	{
		if(current == ' ' || current == '\n' || current == '\t')
		return eatTrivia();

		if(isdigit(current))
		return eatNumeric();

		if(current == '"' || current == '\'')
		return eatString();

		if(isalpha(current))
		return eatID();

		return eatSymbol();
	}

	return token(End, "");
}

lexToken lexer::eatTrivia()
{
	trivia.clear();
	while(current == ' ' || current == '\n' || current == '\t')
	{
		trivia += current;
		advance();
	}
}

lexToken lexer::eatNumeric()
{
	tokenType type = Int;
	std::string data = "";
}

lexToken lexer::eatString()
{
	
}

lexToken lexer::eatSymbol()
{
	
}

lexToken lexer::eatID()
{
	
}