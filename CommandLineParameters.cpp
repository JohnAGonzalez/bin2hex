/*
Program    : BIN2HEX
Description: This is the implementation for the CommandLineParameters class
Author     : John A. Gonzalez
Copyright (c) 2021, All rights reserved
*/

#include "CommandLineParameters.h"

CommandLineParameters::CommandLineParameters(int argc, char** argv)
{
	_isValid = false;

	for (int arg = 1; arg < argc; ++arg)
	{
		switch (arg)
		{
		case 1: // source file
			_source = argv[arg];
			_target = _source + ".hex";
			_isValid = true;
			break;

		case 2: // target file
			_target = argv[arg];
			break;

		default:
			break;	// do nothing with the rest of the arguments
		}
	}
}

CommandLineParameters::~CommandLineParameters()
{
}

std::string CommandLineParameters::getSource()
{
	return _source;
}

std::string CommandLineParameters::getTarget()
{
	return _target;
}

bool CommandLineParameters::isValid()
{
	return _isValid;
}