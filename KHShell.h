/*
 * KHShell.h
 *
 *  Created on: Mar 7, 2017
 *      Author: hel7
 */

#ifndef KHSHELL_H_
#define KHSHELL_H_

#include "CommandLine.h"
#include "Path.h"
#include "Prompt.h"
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <exception>

using namespace std;

class KHShell {
public:

	KHShell();
	void run();
};

#endif /* KHSHELL_H_ */
