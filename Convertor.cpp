/*
Program    : BIN2HEX
Description: This is the implementation for the Convertor class
Author     : John A. Gonzalez
Copyright (c) 2021, All rights reserved
*/

#include "Convertor.h"

#include <fstream>
#include <iomanip>
#include <sstream>

Convertor::Convertor()
{
	_cmdLine = nullptr;
}

Convertor::Convertor(CommandLineParameters& cmdLine)
{
	_cmdLine = &cmdLine;
}

Convertor::~Convertor()
{
}

void Convertor::go()
{
	std::ifstream sourceFile;
	std::ofstream targetFile;
	std::streampos sourceFileSize = 0;
	unsigned int currPos = 0;
	unsigned char* sourceFileContents;
	std::stringstream currByte;

	if (_cmdLine == nullptr || !_cmdLine->isValid())
		return;

	// open the source file
	sourceFile.open(_cmdLine->getSource(), std::ios::binary);
	if (!sourceFile.is_open() || sourceFile.bad())
		return;

	// read the source file into memory
	sourceFile.seekg(0, std::ios::end);
	sourceFileSize = sourceFile.tellg();
	sourceFileContents = new unsigned char[sourceFileSize];
	sourceFile.seekg(0, std::ios::beg);
	sourceFile.read((char *)sourceFileContents, sourceFileSize);
	sourceFile.close();

	// create the target file
	targetFile.open(_cmdLine->getTarget(), std::ios::trunc);
	if (!targetFile.is_open() || targetFile.bad())
	{
		delete[] sourceFileContents;
		return;
	}

	// perform the conversion
	for (currPos = 0; currPos < sourceFileSize; ++currPos)
	{
		if (0 == currPos % 32)	// write a new line header
		{
			if (currPos > 0)	// only write a new line once we have started the file
			{
				targetFile << "\n";
			}

			targetFile << std::setw(8) << std::setfill(' ') << currPos << " ";
		}
		else
		{
			if (0 == currPos % 4)
			{
				targetFile << " ";
			}
		}

		// this makes sure that only a single character will be written to the output at a time
		currByte.str("");
		currByte
			<< std::setw(2)
			<< std::setfill('0')
			<< std::hex
			<< std::uppercase
			<< (unsigned int)((unsigned char)sourceFileContents[currPos]);

		targetFile << currByte.str();
	}

	delete[] sourceFileContents;
	targetFile.close();
}
