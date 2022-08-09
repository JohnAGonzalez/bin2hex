#pragma once
/*
Program    : BIN2HEX
Description: This is the definition for the CommandLineParameters class
Author     : John A. Gonzalez
Copyright (c) 2021, All rights reserved
*/

#include <string>

class CommandLineParameters
{
public:
	// special constructor
	CommandLineParameters(int argc, char** argv);

	// destructor
	~CommandLineParameters();

	// accessors
	std::string getSource();
	std::string getTarget();
	bool isValid();

private:
	std::string _source;
	std::string _target;
	bool _isValid;

};