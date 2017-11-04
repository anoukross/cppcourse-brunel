#include "Experiment.hpp"

using namespace std;

/**
 * The main program
*/

int main(){
	Experiment e; /**< creates a network composed of 12500 neurons, @see Network  */
	e.launchSimulation(1000); //in ms


	return 0;

}
