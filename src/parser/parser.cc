#include "parser/parser.hh"
#include "parser/lexutils.hh"

parser::parser(std::vector<lexToken> tokens) : tokens(tokens), pos(0), current(&tokens[0]) {}

compoundAST parser::parse()
{
  // global variable
  // link something
  // function definition
  // data definition


  // Start off simple lets only parse numeric expressions

  compoundAST compound();

  while(current -> kind != End && pos < tokens.size()) 
  {
    if(current -> kind == Data) 
    { compound.add(parseData()); }
  }
}

void parser::step()
{
  if(pos + 1 < tokens.size()) current = &tokens[pos++];
}

bool parser::peak(int n, tokenType type)
{
  return pos + n < tokens.size() && tokens[pos + n] -> type == type;
}