/// Emil Hedemalm säkert
/// 2015-12-13
/// Very planet-wise.

#include "Ship.h"
#include "Planet.h"

Ship::Ship()
{
	population = 0;
	travelTime = -1;
	deleteThis = false;
	destination = 0;
}

void Ship::Simulate(int iterations, std::iostream & outputStream)
{
	if(travelTime>0)
	{
		travelTime--;
		if(travelTime==0)
		{
			destination->population+=this->population;
			//outputStream<<"\nShip arrived at "<<destination->name<<". Population is now: "<<destination->population;
			deleteThis=true;
			return;
		}
	}
}