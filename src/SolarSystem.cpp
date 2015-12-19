/// Emil Hedemalm
/// 2015-12-13
/// A very cool solar system

#include "Universe.h"
#include "SolarSystem.h"
#include "Planet.h"
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
	for (int q = 0; q < numberOfPlanets; ++q)
	{
		char buffer[5];
		itoa(q+1, buffer, 10);
		Planet * planet = new Planet();
		planets.push_back(planet);
		universe.planets.push_back(planet);
		outputStream<<std::endl<<q+1<<" Planet created.";
		strcpy(planet->name, name);
		strcat(planet->name, buffer);
		planet->solarsystem=this;
		planet->size=rand()%Planet::MAX_SIZES;
		planet->resources=rand()%Planet::MAX_SIZES;
	}
}

void SolarSystem::Simulate(int iterations, std::iostream & outputStream)
{
	// Do something, or just call Simulate for each planet later?
	for(int q=0; q<planets.size(); ++q)
	{
		planets[q]->Simulate(iterations, outputStream);
	}
}

	/// Sums total population.
long long SolarSystem::TotalPopulation()
{
	long long totalPopulation = 0;
	for(int q=0; q<planets.size(); ++q)
	{
		totalPopulation += planets[q]->population;
	}
	return totalPopulation;
}

	/// Destroys a planet.
void SolarSystem::DestroyPlanet(int planetIndex)
{
	Planet * targetPlanet = planets[planetIndex];
}