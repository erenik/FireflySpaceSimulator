/// Emil Hedemalm
/// 2015-12-13
/// A very cool solar system

#include "SolarSystem.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

SolarSystem::SolarSystem(int numberOfPlanets, std::iostream & outputStream)
{
	memset(name, 0, SOLAR_NAME_LENGTH);
	for (int i = 0; i < 4; ++i)
	{
		name[i] = rand() % (90 - 65) + 65;
	}
	for (int q = 0; q < numberOfPlanets; q++)
	{
		Planet planet;
		planets.push_back(planet);
		outputStream<<std::endl<<q+1<<" Planet created.";
	}
}

void SolarSystem::Simulate(int iterations, std::iostream & outputStream)
{
	// Do something, or just call Simulate for each planet later?
}

