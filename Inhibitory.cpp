#include "Inhibitory.hpp"
#include <cassert>

/**
*  Constructor
*/
Inhibitory::Inhibitory(unsigned int index)
/*! \brief The amplitude of the postsynaptic current of an inhibitory neuron = 0.5 mV
*/
:Neuron(index, 0.5)
{
/*! \brief The index of the inhibitory neuron should be between nb_excit(10000) to nb_neurons -1 (12500-1)
*/
assert(index > Network::nb_excit_-1);  
assert(index < Network::nb_neurons_);
}
