#include "lexer/lexer.hh"

#include <ctype.h>

lexer::lexer(std::string source) : 
source(source), trivia(""), current(source[0]), pos(0), line(0), linePos(0) {}

void lexer::step()
{
	if(current != EOF && current != '\0')
	{
		line += (current == '\n');
		linePos *= (current != '\n');
		linePos += (current != '\n');

		pos++;
		current = source[pos];
	}
}

lexToken lexer::token(tokenType type, std::string data)
{
	return *(new lexToken(type, data, trivia, line, linePos - data.size(), linePos));
}

lexToken lexer::next()
{
	while(current != EOF && current != '\0')
	{
		if(current == ' ' || current == '\n' || current == '\t')
		{ eatTrivia(); }

		if(isdigit(current))
		{ return eatNumeric(); }

		if(current == '"' || current == '\'')
		{ return eatString(); }

		if(isalpha(current))
		{ return eatID(); }

		return eatSymbol();
	}

	return token(End, "");
}

void lexer::eatTrivia()
{
	trivia.clear();
	while(current == ' ' || current == '\n' || current == '\t')
	{
		trivia += current;
		step();
	}
}

lexToken lexer::eatNumeric()
{
	std::string data;
	tokenType type = IntType;

	while(isdigit(current) || current == '.')
	{
		data += current;
		if(current == '.')
		{
			if(type == RealType)
			{
				/* Throw error, 2 '.'s */
			}
			type = RealType;
		}

		step();
	}

	return token(type, data);
}

lexToken lexer::eatString()
{
	std::string data;
	char quote = current;
	step();

	while(current != quote && data.back() != '\\')
	{
		if(current == EOF || current == '\0')
		{
			/* Throw error, no matching quote */
			break;
		}

		data += current;
		step();
	}

	step();

	return token(StringType, data);
}

lexToken lexer::eatID()
{
	std::string data;
	bool matching = true;

	lexID matcher;

	while(isalpha(current))
	{
		if(matching) matching = matcher.toNode(current);
		data += current;
		step();
	}

	return token(matching ? matcher.nodeID() : ID, data);
}

lexToken lexer::eatSymbol()
{
  tokenType type;
  std::string data = {current};
  step();

  switch(data.front())
  {
    case '+':
    if(current == '+') { type = PlusPlus; data += current; }
    else type = Plus;

    break; case '-':
    if(current == '-') { type = MinusMinus; data += current; }
    else if(current == '>') { type = ArrowOpen; data += current; }
    else type = Minus;
  
    break; case '*':
		type = Star;

    break; case '\\':
		type = Slash;

    break; case '%':
		type = Percent;

    break; case ':':
		if(current == '+') {type = AssignPlus; data += current; }
		else if(current == '-') {type = AssignMinus; data += current; }
		else if(current == '*') {type = AssignStar; data += current; }
		else if(current == '/') {type = AssignSlash; data += current; }
		else if(current == '%') {type = AssignPercent; data += current; }
    else type = Assign;

    break; case '=':
    type = Eq;

    break; case '>':
    if(current == '=') { type = GtEq; data += current; }
    else type = Gt;

    break; case '<':
    if(current == '=') { type = LtEq; data += current; }
    if(current == '-') { type = ArrowClose; data += current; }
    else type = Lt;

    break; case '!':
    if(current == '=') { type = BangEq; data += current; }
    else type = Bang;

    break; case '(':
    type = ParenClose;

    break; case ')':
    type = ParenOpen;

    break; case '[':
    type = SquareClose;

    break; case ']':
    type = SquareOpen;

    break; case ',':
    type = Comma;

    break; case '.':
    if(current == '.') { type = DotDot; data += current; }
    else type = Dot;

    break; default:
		/* Throw unexpected token error with current */
    return next();
  }

  if(data.size() == 2) step();
  return token(type, data);
}