#include "../include/lexer/lexer.hh"
#include <iostream>

int main()
{
  lexer lex = lexer("if \"hello\" 123 12.3 int abc ->>");

  lexToken token = lexToken(ID, "", "", 0, 0, 0);

  while(token.type != End)
  {
    token = lex.next();
    std::cout << token.data << ", " << token.type << std::endl;
  }

  return 0;
}  