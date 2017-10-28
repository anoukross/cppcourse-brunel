#ifndef INHIBITORY_HPP
#define INHIBITORY_HPP

#include "Neuron.hpp"




class Inhibitory: public Neuron{	
	public:
	
		/**
		*  Constructor
		* calls the constructor of Neuron with index and the amplitude of the postsynaptic current for the inhibitory neurons (Ji) = 0.5 mV
        * @param index  the index of the inhibitory neuron goes from nb_excit(10000) to nb_neurons -1 (12500-1)
        */
		Inhibitory(unsigned int index);
	
	
};

#endif

