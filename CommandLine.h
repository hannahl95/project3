/*
 * Header file for the Command Line Class
 *
 *  Created on: Mar 7, 2017
 *      Author: Kyle Reitsma
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class CommandLine {

vector<string> strings;
bool hasNoAmpersand;

public:

	CommandLine(istream& in) {
		// Get a string from the commandline
		char* commands = new char[256];
		in.getline(commands, 256);

		hasNoAmpersand = true;

		// Use istringstream to parse string into array (credit to Spider-main of Stack Overflow for the code)
		istringstream s(commands);
		string tmp;

		while (s >> tmp) {
			if (tmp.find("&") != string::npos) 
			{
				hasNoAmpersand = false;
			}
			else if ((tmp.find(' ') == string::npos) && (tmp.find('\n') == string::npos))
			{
				strings.push_back(tmp);
			}
		}
	}
	const char* getCommand() const;
	int getArgCount() const;
	char** getArgVector() const;
	char* getArgVector(int i) const;
	bool noAmpersand() const;
};

#endif /* COMMANDLINE_H_ */
