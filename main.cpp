/*
Program    : BIN2HEX
Description: This program reads a file specified by the user and converts
             the contents of that file to the HEX representation of the
			 source file.  There are two command-line parameters that are
			 required, the path of the source file and the path to the
			 target file.
Author     : John A. Gonzalez
Copyright (c) 2021, All rights reserved
*/

#include "main.h"

int main(int argc, char** argv)
{
	// check the command-line parameters
	CommandLineParameters cmdLine(argc, argv);

	Convertor convertor(cmdLine);
	convertor.go();

	return 0;
}