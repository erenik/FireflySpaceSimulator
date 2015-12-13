/// Emil Hedemalm
/// 2015-12-13
/// A very cool solar system

#include "SolarSystem.h"
#include <cstring>
#include <cstdlib>

SolarSystem::SolarSystem()
{
	memset(name, 0, SOLAR_NAME_LENGTH);
	for (int i = 0; i < 4; ++i)
	{
		name[i] = rand() % (90 - 65) + 65;
	}
}

void SolarSystem::Simulate(int iterations, std::iostream & outputStream)
{
	// Do something, or just call Simulate for each planet later?
}

