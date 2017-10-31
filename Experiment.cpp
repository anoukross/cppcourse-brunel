#include "Experiment.hpp"

void Experiment::launchSimulation(unsigned int steps_number){
	Network net;
	for(unsigned int t(1); t<steps_number; ++t){
			/*! \brief There is no update when the time is equal to 0
			*/
			net.update(t);
							
	} 
	
}
