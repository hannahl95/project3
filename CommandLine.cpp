/*
 * Class CommandLine that reads a command line from a user
 *
 *  Created on: Mar 7, 2017
 *      Author: Kyle Reitsma
 */

#include "CommandLine.h"

// Returns command
const char* CommandLine::getCommand() const
{
	return strings[0].c_str();
}

// Gets arg count (i.e. argc)
int CommandLine::getArgCount() const
{
	return strings.size();
}

// Gets arg array (i.e. argv)
char** CommandLine::getArgVector() const
{
	char** args = new char*[strings.size()+1];
	
	int i = 0;
	for ( i; i < strings.size(); i++) {
		args[i] = (char*)(strings[i]).c_str();
	}
	args[i+1] = (char*)0;

	return args;
}

// Gets arg in the arg array (i.e. argv[i])
char* CommandLine::getArgVector(int i) const
{
	return (char*)strings[i].c_str();
}


// Checks if there is an ampersand in any arguments
bool CommandLine::noAmpersand() const
{
	return hasNoAmpersand; 
}

