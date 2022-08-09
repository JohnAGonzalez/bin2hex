#pragma once
/*
Program    : BIN2HEX
Description: This is the definition for the Convertor class
Author     : John A. Gonzalez
Copyright (c) 2021, All rights reserved
*/

#include "CommandLineParameters.h"

class Convertor
{
public:
	// special constructor
	Convertor();
	Convertor(CommandLineParameters& cmdLine);

	// destructor
	~Convertor();

	// public methods
	void go();

private:
	CommandLineParameters * _cmdLine;

};
