/*
 * Class Path that represents the directories in which the shell searches for executable
 *
 *  Created on: Mar 7, 2017
 *      Author: Hannah Ludema
 */

#include "Path.h"

//Constructs the path from the path environment vaiable
Path::Path() {

	//Gets the path environment
	char* path = getenv("PATH");
	if (path != NULL)
	{
		for (int i=0; i<strlen(path); i++)
		{
		    if (path[i] == ':')
		        path[i] = ' ';
		}

		//Stores each directory in a vector of strings
		stringstream ss(path);
		string temp;
		while (ss >> temp)
		    directories.push_back(temp);
	}
}

//Returns the index of the directory containing program
int Path::find(const string& program) const
{
	DIR* dir;
	struct dirent* next;

	//For each directory
	for( int i=0; i<directories.size(); i++)
	{
		//Open the directory and see if the given program is in it
		dir = opendir( directories[i].c_str() );
		if ( dir != NULL )
		{
			while (( next = readdir( dir )) != NULL )
			{
				if ( program == next->d_name )
				{
					closedir( dir );
					return i;
				}
			}

		}
		closedir( dir );
	}
	return -1;

}
//Returns the name of the directory at index i
string Path::getDirectory(int i) const
{
	return directories[i];
}
