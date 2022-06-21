#include "lexer/lexutils.hh"
#include "lexer/lexid.hh"
#include <iostream>

bool lexID::toNode(char node)
{
  int N = lexTrie[pos + 1];

  for(int i = 0; i < N; i++)
  {
    if(lexTrie[pos + 2 + 2 * i] == node)
    {
      pos = lexTrie[pos + 3 + 2 * i];
      return true;
    }
  }

  return false;
}

tokenType lexID::nodeID()
{
  return (tokenType)lexTrie[pos];
}