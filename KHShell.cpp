/*
 * KHShell.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: hel7
 */

#include "KHShell.h"

KHShell::KHShell() 
{


}

void KHShell::run() {

	int dirIndex;
	string dir;
	const char* directory;
	const char* command;
	char * filename;
	int change;
	string currentPath;
	string path;
	char* argVec;
	char* arg1;
	const char* arg2;
	char * newPath;
	int execution;
	int status;
	Path myPath;

	while ( true ) {
		//Get the prompt and ask for command line input
		Prompt myPrompt;
		cout << myPrompt.get();
		CommandLine myCommand( cin );
		
		//Get the directory of a command
		dirIndex = myPath.find(myCommand.getCommand());
		dir = myPath.getDirectory( dirIndex );

		//Concat the command and its path
		directory = dir.c_str();
		command = myCommand.getCommand();
		filename = new char[strlen(directory) + strlen(command) + 1];
		strcpy(filename, directory);
		strcat(filename, "/");
		strcat(filename, command);

		//Handle exit and cd 
		if ( strcmp(command, "exit") == 0 ){
			break;
		}
		else if ( strcmp(command, "cd") == 0 ){
			currentPath = myPrompt.get();
			argVec = myCommand.getArgVector(1);

			//Handle cd
			if( myCommand.getArgCount() == 1 ){
				change = chdir("/");
			}
			//Handle cd ..
			else if ( strcmp(argVec, "..") == 0 ) {
				
				path = currentPath.substr(0, currentPath.find_last_of("/"));
				try{
					change = chdir(path.c_str());
				}
				catch( const std::bad_alloc& ){
					cout << "No such directory";
				}
			}
			//Handle if the user cd's into a new directory
			else {
				arg1 = argVec;
				arg2 = (currentPath.substr(0, currentPath.find("$"))).c_str();
				newPath = new char[strlen(arg1) + strlen(arg2) + 1];
				strcpy(newPath, arg2);
				strcat(newPath, "/");
				strcat(newPath, arg1);
				try{
					change = chdir(newPath);
				}
				catch( const std::bad_alloc& ){
					cout << "No such directory";
				}
			}
			if ( change == -1){
				cout << "No such directory";
			} 
		}
		//Execute other commands given
		else {

			pid_t pid = 0;
			pid = fork();

			//The child thread
			if ( pid == 0 ) {
			
				try 
				{
					execution = execve( filename, myCommand.getArgVector(), NULL);
					if ( execution == -1 )
					{
						cout << "That command is invalid\n";
					}
				}
				catch( exception& e )
				{
					cout << "There was an error\n";
				}
			}
			//The parent thread
			else if (pid > 0) {
				if ( myCommand.noAmpersand() )
				{
					waitpid( pid, &status, 0 );
	 			}
			}
			//Check if it fails
			else{
				cout << "Fork failed";
			}
		}
	}

}


int main()
{
  KHShell myShell;
  myShell.run();
}
