#ifndef EXCITATORY_HPP
#define EXCITATORY_HPP

#include "Neuron.hpp"
#include "Network.hpp"


/**
 *  The Excitatory class which is a subclass of Neuron
 */
class Excitatory: public Neuron{	
	public:
		
		/**
		*  Constructor
		* calls the constructor of Neuron with index and the amplitude of the postsynaptic current for the excitatory neurons (Je) = 0.1 mV
        * @param index  the index of the excitaory neuron goes from 0 to nb_excit-1(10000-1)
        */
		Excitatory(unsigned int index);

	
	
};

#endif

