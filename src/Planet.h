/// Emil Hedemalm
/// 2015-12-13
/// Very planet-wise.

#ifndef PLANET_H
#define PLANET_H

#include <iostream>

class Planet 
{
public:
	long population;
	/// Earth evacuation
	bool isBeingEvacuated;
	Planet();
	void Simulate(int iterations, std::iostream & outputstream);
	int hour;

};

#endif

