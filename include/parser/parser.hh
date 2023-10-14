#pragma once
#include "lexer/lexer.hh"
#include "astnode.hh"

struct parser
{
  std::vector<lexToken> tokens;
  lexToken* current;
  int pos;

  parser(std::vector<lexToken> tokens);

  compoundAST parse();

  void step();
  lexToken* parser::consume() 
  bool parser::peak(int n, tokenType type)

  expAST parseExp();
}