/// Emil Hedemalm
/// 2015-12-13
/// A universe to be simulated...!

#include "Universe.h"
#include "Planet.h"

Universe universe;

Universe::~Universe()
{
}
///	Creates the universe.
void Universe::CreateUniverse(int solarSystemsToCreate, std::iostream & outputStream)
{
	/// Creates solar systems.
	for (int i = 0; i < solarSystemsToCreate; ++i)
	{
		int temp = rand()%9+1;
		SolarSystem system(temp, outputStream);
		solarSystems.push_back(system);
		outputStream<<"\nSolar system created: "<<system.name;
	}
	/// Appoint Earth.
	int temp2 = rand()%solarSystems.size();
	SolarSystem & randomedSolarsystem = solarSystems[temp2];
	int temp3 = rand()%randomedSolarsystem.planets.size();
	Planet * randomedPlanet = randomedSolarsystem.planets[temp3];
	randomedPlanet->population = 2000000000;
	randomedPlanet->isBeingEvacuated = true;

	/// Print total population.
	outputStream<<"\nTotal Population: "<<TotalPopulation();

	/// Kill Earth and create ships.
//	DestroyPlanet();
}

/// Simulates the universe.
void Universe::Simulate(int iterations, std::iostream & outputStream)
{
	for (int i = 0; i < iterations; ++i)
	{
		outputStream<<"\nSimulating iteration "<<i;
		
		for (int i = 0; i < solarSystems.size(); ++i)
		{
			solarSystems[i].Simulate(iterations, outputStream);
		}
		outputStream<<"\nTotal Population: "<<TotalPopulation();
	}
}

/// Sums total population.
long Universe::TotalPopulation()
{
	long totalPopulation = 0;
	for(int q=0; q<solarSystems.size(); ++q)
	{
		totalPopulation += solarSystems[q].TotalPopulation();
	}
	return totalPopulation;
}

