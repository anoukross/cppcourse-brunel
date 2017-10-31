#ifndef EXPERIMENT_HPP
#define EXPERIMENT_HPP

#include "Network.hpp"
#include "Neuron.hpp"



/**
 *  The Experiment class
 */
class Experiment{	
	public:
		void launchSimulation(unsigned int steps_number);
		static void fetchData(unsigned int time_steps, unsigned int indice);

	
	
};

#endif
