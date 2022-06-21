#include "lexer/lexutils.hh"

lexToken::lexToken(tokenType type, std::string data, std::string trivia, int line, int start, int end) :
type(type), data(data), trivia(trivia), line(line), start(start), end(end) {}