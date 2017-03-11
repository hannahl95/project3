/*
 * Header file for the Path class
 *
 *  Created on: Mar 7, 2017
 *      Author: Hannah Ludema
 */

#ifndef PATH_H_
#define PATH_H_

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sstream>
#include <vector>

using namespace std;

class Path {
public:
	vector<string>  directories;

	Path();
	int find(const string& program) const;
	string getDirectory(int i) const;
};

#endif /* PATH_H_ */
