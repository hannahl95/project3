/*
 * Header file for the Prompt class
 *
 *  Created on: Mar 7, 2017
 *      Author:	Hannah Ludema
 */

#ifndef PROMPT_H_
#define PROMPT_H_

#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>

using namespace std;

class Prompt {
public:
	string prompt;

	Prompt();
	string get() const;
};

#endif /* PROMPT_H_ */
