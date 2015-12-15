/// Karl Wängberg
/// 2015-12-13
/// A very cool planet

#include <iostream>
#include "Planet.h"
#include "Universe.h"
#include "Ship.h"

//Population and stuff, so far
Planet::Planet()
{
	population=0;
	isBeingEvacuated = false;
	hour = 0;
}

/// Simulates the planet.
void Planet::Simulate(int iterations, std::iostream & outputStream)
{
	for (int i = 0; i < iterations; ++i)
	{
		hour++;
		outputStream<<"\nSimulating iteration "<<i;
		if(hour>=24)
		{
			hour=0;
			if(isBeingEvacuated)
			{
				///Creates some ships.
				Ship ship;
				ship.population = 50;
				population -= 50;
				universe.ships.push_back(ship);
			}
		}
	}
}