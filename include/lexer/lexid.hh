#pragma once

#include "lexiddata.hh"

struct lexID
{
	int pos;
	
	lexID();
	bool toChild(char child);
}