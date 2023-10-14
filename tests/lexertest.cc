#include "../include/lexer/lexer.hh"
#include <iostream>

int main()
{
  errorHandler handler;

  lexer lex = lexer("if dot if else 123 12.3 \"string\" ^ |}\n $$#$#$#", handler);

  lexToken token = lexToken(ID, "", "", 0, 0, 0);

  while(token.type != End)
  {
    token = lex.next();
    std::cout << token.data << ", " << token.type << std::endl;
  }

  std::vector<error> errors = handler.getErrors();

  for(error &e : errors) 
  {
    std::cout << e.name << " [" << e.code << "] " << std::endl  << e.line << ":" << e.linePos << " " << e.message << std::endl << std::endl;
  }

  return 0;
}