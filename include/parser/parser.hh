#pragma once
#include "lexer/lexer.hh"

struct parser
{
  std::vector<lexToken> tokens;
  lexToken* current;
  int pos;

  parse();

  void step();
  lexToken* peak(int n); 
}