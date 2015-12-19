/// Emil Hedemalm
/// 2015-12-13
/// Very planet-wise.

#ifndef PLANET_H
#define PLANET_H

#include <iostream>

class SolarSystem;

class Planet 
{
public:
	long long population;
	/// Earth evacuation
	bool isBeingEvacuated;
	Planet();
	void Simulate(int iterations, std::iostream & outputstream);
	enum {	SMALLEST, NONE=SMALLEST,
			SMALL,
			MEDIUM,
			LARGE,
			LARGEST,
			MAX_SIZES
		};
	int size;
	int resources;
	int hour;
	int day;
	float growthFactor;
	SolarSystem * solarsystem;
	char name[40];
	void IncreasePopulation();
};

#endif

