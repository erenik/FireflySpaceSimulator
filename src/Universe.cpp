/// Emil Hedemalm
/// 2015-12-13
/// A universe to be simulated...!

#include "Universe.h"

/// Simulates the universe.
void Universe::Simulate(int iterations, std::fstream & outputFile)
{
	for (int i = 0; i < iterations; ++i)
	{
		outputFile<<"\nSimulating iteration "<<i;
	}
}


