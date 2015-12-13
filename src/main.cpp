/// Emil Hedemalm
/// 2015-12-13
/// very code.

#include <iostream>
#include <fstream>
#include "Universe.h"
#include <Windows.h>

int main(int argc, char ** argv)
{
	std::cout<<"\nHello world!";
	std::fstream outputFile("SimulationOutput.log", std::ios_base::out);
	if (!outputFile.is_open())
	{
		std::cout<<"\nUnable to open output file.. D:";
		return false;
	}
	Universe universe;
	universe.Simulate(1000, outputFile);
	Sleep(1000);
	return 0;
}
