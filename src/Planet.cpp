/// Karl Wängberg
/// 2015-12-13
/// A very cool planet

#include <iostream>
#include "Planet.h"
#include "Ship.h"
#include "Universe.h"

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
	Ship ship;
	for (int i = 0; i < iterations; ++i)
	{
		hour++;
		if(hour>=24)
		{
			hour=0;
			if(isBeingEvacuated)
			{
				///Creates some ships.
				for(int q = 0; q<500; q++)
				{
					Ship * ship = new Ship();
					if(q==200) std::cout<<"\nShip count: "<<universe.ships.size();
					ship->population = 50;
					population -= 50;
					universe.ships.push_back(ship);
					ship->destination = universe.GetNewPlanetToBeColonised(this);
					ship->travelTime = universe.GetTravelTime(ship->destination, this);
				}
			}
			else 
			{
				population *= 1.00001;
			}
		}
	}
}