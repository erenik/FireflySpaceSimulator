/// Emil Hedemalm
/// 2015-12-13
/// A universe to be simulated...!

#include "Universe.h"
#include "Planet.h"
#include "Ship.h"

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
		SolarSystem * system = new SolarSystem(temp, outputStream);
		solarSystems.push_back(system);
		outputStream<<"\nSolar system created: "<<system->name;
	}
	/// Appoint Earth.
	int temp2 = rand()%solarSystems.size();
	SolarSystem * randomedSolarsystem = solarSystems[temp2];
	int temp3 = rand()%randomedSolarsystem->planets.size();
	Planet * randomedPlanet = randomedSolarsystem->planets[temp3];
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
		//outputStream<<"\nSimulating iteration "<<i;
		
		for (int q = 0; q < solarSystems.size(); ++q)
		{
			solarSystems[q]->Simulate(1, outputStream);
		}
		
		for(int w = 0; w<ships.size(); w++)
		{
			Ship * ship = ships[w];
			ship->Simulate(1, outputStream);
			if(ship->deleteThis)
			{
				ships.erase(ships.begin()+w);
				delete ship;
				continue;
			}
		}
	}
}

/// Sums total population.
long long Universe::TotalPopulation()
{
	long long totalPopulation = 0;
	for(int w=0; w<ships.size(); ++w)
	{
		totalPopulation += ships[w]->population;
	}
	for(int q=0; q<solarSystems.size(); ++q)
	{
		totalPopulation += solarSystems[q]->TotalPopulation();
	}
	return totalPopulation;
}

Planet * Universe::GetNewPlanetToBeColonised(Planet * originPlanet)
{
	int probability;
	int totalProbability = 0;
	std::vector<int> probabilities;

	for(int q=0; q<planets.size(); ++q)
	{
		Planet * planet = planets[q];
		int population = planet->population;
		
		if(planet->isBeingEvacuated)
		{
			probability = 0;
		}
		else if(population>1000)
		{
			probability = 1;
		}
		else if(population>500)
		{
			probability = 2;
		}
		else if(population>200)
		{
			probability = 3;
		}
		else if(population>100)
		{
			probability = 5;
		}
		else if(population>50)
		{
			probability = 10;
		}
		else 
		{
			probability = 15;
		}
		probabilities.push_back(probability);
		totalProbability += probability;
	}
	int randomedValue = rand()%totalProbability;

	for(int w = 0; w<planets.size(); ++w)
	{
		randomedValue -= probabilities[w];

		if(randomedValue<=0)
		{
			return planets[w];
		}
	}
	return 0;
}

int Universe::GetTravelTime(Planet * destination, Planet * origin)
{
	if(destination->solarsystem==origin->solarsystem)
	{
		return 240;
	}
	return 720;
}

void Universe::PrintStatistics(std::iostream & outputStream)
{
	for(int q=0; q<solarSystems.size(); ++q)
	{
		outputStream<<"\nSolarsystem "<<q+1<<" Population: "<<solarSystems[q]->TotalPopulation();
		for(int w=0; w<solarSystems[q]->planets.size(); ++w)
		{
			outputStream<<"\nPlanet "<<w+1<<" of system Population: "<<solarSystems[q]->planets[w]->population;
		}

	}
}