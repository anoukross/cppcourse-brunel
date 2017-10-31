#include "Experiment.hpp"

using namespace std;

/**
 * The main program
*/

int main(){
	Experiment e; /**< creates a network composed 12500 neurons, @see Network  */
	e.launchSimulation(10000);
	
	
	return 0;
	
}
