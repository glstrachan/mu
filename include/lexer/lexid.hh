#pragma once
#include "lexer/lexutils.hh"

struct lexID
{
	static constexpr int lexTrie[] = lexTrieTemplate;
	int pos = 0;
	
	bool toNode(char node);
	tokenType nodeID();
};