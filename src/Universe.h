/// Emil Hedemalm
/// 2015-12-13
/// A universe to be simulated...!

#include <fstream>
#include <vector>
#include "SolarSystem.h"
class Ship;

class Planet;
class Universe 
{
public:
	~Universe();
	/// Creates the universe.
	void CreateUniverse(int solarSystemsToCreate, std::iostream & outputStream);
	/// Simulates the universe.
	void Simulate(int iterations, std::iostream & outputStream);
	/// Sums total population.
	long long TotalPopulation();
	/// Finds a new planet
	Planet * GetNewPlanetToBeColonised(Planet*);
	int GetTravelTime(Planet * destination, Planet * origin);
	std::vector<SolarSystem*> solarSystems;
	std::vector<Ship*> ships;
	std::vector<Planet*> planets;
	void PrintStatistics(std::iostream & outputStream);
};

extern Universe universe;

