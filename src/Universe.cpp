/// Emil Hedemalm
/// 2015-12-13
/// A universe to be simulated...!

#include "Universe.h"

Universe::~Universe()
{
}

void Universe::CreateUniverse(int solarSystemsToCreate, std::iostream & outputStream)
{
	/// Create solar systems.
	for (int i = 0; i < solarSystemsToCreate; ++i)
	{
		int temp = rand()%9+1;
		SolarSystem system(temp, outputStream);
		solarSystems.push_back(system);
		outputStream<<"\nSolar system created: "<<system.name;
	}
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
	}
}


