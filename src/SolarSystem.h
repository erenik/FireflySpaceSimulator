/// Emil Hedemalm
/// 2015-12-13
/// A very cool solar system

class Planet;
#include <vector>

class SolarSystem 
{
public:
	SolarSystem(int numberOfPlanets, std::iostream & outputStream);
	void Simulate(int iterations, std::iostream & outputStream);
	/// Sums total population.
	long TotalPopulation();
	/// Destroys a planet.
	void DestroyPlanet(int planetIndex);

#define SOLAR_NAME_LENGTH 20
	char name[SOLAR_NAME_LENGTH];

	/// 1-9 planets
	std::vector<Planet*> planets;

};


