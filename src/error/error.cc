#include "error/error.hh"

error::error(int line, int linePos) : line(line), linePos(linePos) {}

unexpectedChar::unexpectedChar(char c, int line, int linePos) : error(line, linePos) 
{
    name = "Unexpected Character";
    code = "LUC";
    message = "character \'" + std::string(1, c) + "\' unexpected";
} 

expectedChar::expectedChar(char c, int line, int linePos) : error(line, linePos)
{
    name = "Expected Character";
    code = "LEC";
    message = "character \'" + std::string(1, c) + "\' expected";
}

void errorHandler::add(error e)
{
    errors.push_back(e);
}

std::vector<error> errorHandler::getErrors() 
{
    return errors;
}