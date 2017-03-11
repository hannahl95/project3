/*
 * The class Prompt that respresents the command line prompt
 *
 *  Created on: Mar 7, 2017
 *      Author: Hannah Ludema
 */

#include "Prompt.h"

//Builds the prompt as the full path to the working directory
Prompt::Prompt() {

	char* cwd;
	prompt = "";

	//Get the current working directory and store it in prompt
	cwd = getcwd( NULL, 0 );
	if ( cwd != NULL )
	{
		string str(cwd);
		prompt = str + "$ ";
	}
}

//Returns the current value of prompt
string Prompt::get() const{
	//return the prompt
	return prompt;
}


