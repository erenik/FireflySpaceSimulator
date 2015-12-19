/// Emil Hedemalm säkert
/// 2015-12-13
/// Very planet-wise.

#ifndef SHIP_H
#define SHIP_H

#include <iostream>

class Planet;
class Ship
{
public:
	Planet * destination;
	Ship();
	int population;
	int travelTime;
	bool deleteThis;
	void Ship::Simulate(int iterations, std::iostream & outputStream);
};

#endif