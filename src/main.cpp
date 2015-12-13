/// Emil Hedemalm
/// 2015-12-13
/// very code.

#include <iostream>
#include <fstream>
#include "Universe.h"
#include <Windows.h>
#include <sstream>

int main(int argc, char ** argv)
{
	std::cout<<"\nHello world!";
	std::fstream outputFile("SimulationOutput.log", std::ios_base::out);
	if (!outputFile.is_open())
	{
		std::cout<<"\nUnable to open output file.. D:";
		return false;
	}
	std::stringstream stringStream;
	Universe universe;
	universe.CreateUniverse(4, stringStream);
	universe.Simulate(100, stringStream);
	std::cout<<stringStream.str();
	outputFile<<stringStream.str();
	Sleep(1000);
	return 0;
}
