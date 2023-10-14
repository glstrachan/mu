#pragma once

#include <string>
#include <vector>

struct error 
{
    std::string name;
    std::string code;
    std::string message;

    int line;
    int linePos;

    error(int line, int linePos);
};

struct unexpectedChar : error 
{
    unexpectedChar(char c, int line, int linePos);
};

struct expectedChar : error 
{
    expectedChar(char c, int line, int linePos);
};

struct errorHandler 
{
    std::vector<error> errors;

    void add(error);
    std::vector<error> getErrors();
};