/* What Lextoken it is if any */
/* Num children */
/* Character that is the int */
/* Position in array for that child */

/* Identifier AKA ID is assigned val = 0 */


#include <string>
#include <vector>
#include <iostream>
#include <fstream>

const std::string path = "../include/lexer/lexutils.hh";

const std::vector<std::string> keywords =
{
  "if",
  "else",
  "or",
  "and",
  "while",
  "for",
  "break",
  "continue",

  "auto",
  "real",
  "int",
  "string",
  "bit",
  "char",
  "enum",
  "data",

  "final",
  "return"
};

const std::string symbols[] =
{
  "Unknown",
  "PlusPlus",
  "Plus",
  "MinusMinus",
  "ArrowOpen",
  "Minus",
  "Star",
  "Slash",
  "Percent",
  "AssignPlus",
  "AssignMinus",
  "AssignStar",
  "AssignSlash",
  "AssignPercent",
  "Assign",
  "Eq",
  "GtEq",
  "Gt",
  "LtEq",
  "ArrowClose",
  "Lt",
  "BangEq",
  "Bang",
  "ParenClose",
  "ParenOpen",
  "SquareClose",
  "SquareOpen",
  "Comma",
  "DotDot",
  "Dot",
  "End"
};

const std::string types[] = 
{
  "real",
  "int",
  "string",
  "char"
};

struct node
{
  int type;
  char c;
  int index;
  std::vector<node*> nodes;
  node(int type, char c) : type(type), c(c), index(0) {};
};

node trie()
{
  node head = *(new node(0, 0));
  
  for(int i = 0; i < keywords.size(); i++)
  {
    node* current = &head;

    std::string keyword = keywords[i];

    for(int j = 0; j < keyword.size(); j++)
    {
      char c = keyword[j];
      int type = (j + 1 == keyword.size() ? i + 1 : 0);

      bool match = false;

      for(int k = 0; k < current -> nodes.size(); k++)
      {
        if(current -> nodes[k] -> c == c && current -> nodes[k] -> type == type)
        {
          current = current -> nodes[k];
          match = true;
        }
        
      }

      if(!match)
      {
        node* child = new node(type, keyword[j]);
        current -> nodes.push_back(child);
        current = child;
      }
    }
  }

  return head;
}

std::vector<int> compress(node head)
{
  std::vector<int> headTrie;
  headTrie.push_back(head.type);
  headTrie.push_back(head.nodes.size());

  for(auto node : head.nodes)
  {
    headTrie.push_back((int)(node -> c));
    headTrie.push_back(node -> index);
  }

  for(auto node : head.nodes)
  {
    std::vector<int> tailTrie = compress(*node);
    headTrie.reserve(headTrie.size() + tailTrie.size());
    headTrie.insert(headTrie.end(), tailTrie.begin(), tailTrie.end());
  }

  return headTrie;
}

int index(node* head, int offset)
{
  head -> index = offset;
  offset += 2 + (head -> nodes.size()) * 2;

  for(auto node : head -> nodes)
  {
    offset = index(node, offset);
  }

  return offset;
}

int main()
{
  node head = trie();
  index(&head, 0);
  std::vector<int> compTrie = compress(head);

  std::ofstream file(path);

  file << "#pragma once" << std::endl << std::endl;
  file << "enum tokenType : unsigned int" << std::endl;
  file << "{" << std::endl;

  file << "  ID," << std::endl << std::endl;

  /* Capitalize first letter */
  for(auto keyword : keywords)
  {
    file << "  "
    << (char)(keyword[0] - 32) + keyword.substr(1) 
    << "," << std::endl;
  }

  file << std::endl;

  for(auto symbol : symbols)
  {
    file << "  " << symbol << "," << std::endl;
  }

  file << std::endl;

  for(auto type : types)
  {
    file << "  "
    << (char)(type[0] - 32) + type.substr(1) + "Type"
    << "," << std::endl;
  }

  file << "};" << std::endl << std::endl;
  file << "#include \"lexer/lextoken.hh\"" << std::endl << std::endl;
  file << "#define lexTrieTemplate { ";

  for(int i : compTrie) file << i << ", ";

  file << "};" << std::endl;

  file.close();

  return 0;
}
