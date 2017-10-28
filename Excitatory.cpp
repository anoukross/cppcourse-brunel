#include "Excitatory.hpp"
#include <cassert>


/**
*  Constructor
*/
Excitatory::Excitatory(unsigned int index)
/*! \brief The amplitude of the postsynaptic current of an excitatory neuron = 0.1 mV
*/
:Neuron(index, 0.1)
{
/*! \brief The index of the excitatory neuron should be between 0 and nb_excit -1 (10000-1)
*/
assert(index < 10000);  
assert(index>= 0);
}
