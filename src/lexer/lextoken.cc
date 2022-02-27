#pragma once

lexToken::lexToken(tokenType type, std::string data, std::string trivia, int line, int pos) :
type(type), data(data), trivia(trivia), line(line), pos(pos) {}