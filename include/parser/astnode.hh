#pragma once

#include "lexer/lexer.hh"
#include <string>
#include <vector>

struct AST
{
  std::string astType;
};

/* Compound node of all AST nodes */
struct compoundAST
{
  std::vector<*AST> data;

  add(*AST node)
};

struct expAST : AST
{
  std::string type;
};

struct intExpAST : public expAST
{
  int data;
};

struct realExpAST : public expAST
{
  double data;
};

struct stringExpAST : public expAST
{
  std::string data;
};

struct varExpAST : public expAST
{
  std::string name;
};

/* Binary Operator */
struct binExpAST : public expAST
{
  expAST left;
  expAST right;
  tokenType type;
};

struct callExpAST : public expAST
{
  std::string name;
  std::vector<expAST> args;
};

/* Declaration */
struct decAST : AST
{
  std::string type;
  std::string name;
};

struct functionAST : AST
{
  std::string name;
  std::vector<std::string> argnames;
  std::vector<std::string> argtypes;
};