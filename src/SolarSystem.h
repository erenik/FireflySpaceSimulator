/// Emil Hedemalm
/// 2015-12-13
/// A very cool solar system

#include "Planet.h"
#include <vector>

class SolarSystem 
{
public:
	SolarSystem();
	void Simulate(int iterations, std::iostream & outputStream);


#define SOLAR_NAME_LENGTH 20
	char name[SOLAR_NAME_LENGTH];

	/// 1-9 planets
	std::vector<Planet> planets;

};


