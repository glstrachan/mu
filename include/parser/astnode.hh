#pragma once

#include "lexer/lexer.hh"
#include <string>
#include <vector>

struct AST
{
  std::string astType;
}

struct expAST : AST
{
  std::string type;
}

struct intExpAST : public expAST
{
  int data;
}

struct realExpAST : public expAST
{
  double data;
}

struct stringExpAST : public expAST
{
  std::string data;
}

struct varExpAST : public expAST
{
  std::string name;
}

struct binExpAST : public expAST
{
  tokenType type;
}

struct callExpAST : public expAST
{
  std::string name;
  std::vector<expATS> args;
}

struct decAST : AST
{
  std::string type;
  std::string name;
}

struct functionAST : AST
{
  std::string name;
  std::vector<std::string> argnames;
  std::vector<std::string> argtypes;
}