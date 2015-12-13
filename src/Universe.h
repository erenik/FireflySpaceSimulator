/// Emil Hedemalm
/// 2015-12-13
/// A universe to be simulated...!

#include <fstream>
#include <vector>
#include "SolarSystem.h"

class Universe 
{
public:
	~Universe();
	/// Creates the universe
	void CreateUniverse(int solarSystemsToCreate, std::iostream & outputStream);
	/// Simulates the universe.
	void Simulate(int iterations, std::iostream & outputStream);

	std::vector<SolarSystem> solarSystems;

};

