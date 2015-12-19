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
	day = 0;
	size = -1;
	resources = -1;
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
			day++;
			if(day>=30)
			{
				day = 0;
				IncreasePopulation();
			}
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
		}
	}
}

void Planet::IncreasePopulation()
{
	growthFactor = 0.0005;
	switch(this->size)
	{
		case SMALLEST: break;
		case SMALL: growthFactor += 0.0025; break;	
		case MEDIUM: growthFactor += 0.0045; break;
		case LARGE: growthFactor += 0.0075; break;
		case LARGEST: growthFactor += 0.0115; break;
	}
	switch(this->resources)
	{
		case NONE: growthFactor = 0; break;
		case SMALL: growthFactor += 0.0025; break;	
		case MEDIUM: growthFactor += 0.0045; break;
		case LARGE: growthFactor += 0.0075; break;
		case LARGEST: growthFactor += 0.0115; break;
	}
	this->population*=1+growthFactor;
}