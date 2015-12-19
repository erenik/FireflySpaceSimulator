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
	universe.CreateUniverse(4, stringStream);
	for(int q = 0; q<100; ++q)
	{
		universe.Simulate(24, stringStream);
		stringStream<<"\nTotal Population: "<<universe.TotalPopulation()<<" Active ships: "<<universe.ships.size();
	}
	std::cout<<stringStream.str();
	outputFile<<stringStream.str();
	Sleep(1000);
	return 0;
}
