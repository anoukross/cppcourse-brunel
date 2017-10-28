#include "Excitatory.hpp"
#include <cassert>


//Constructeur et destructeur

Excitatory::Excitatory(unsigned int index)
:Neuron(index, 0.1) //Je = 0.1mV
{
assert(index < 10000);  //The index of the excitatory neuron should be between 0 and nb_excit -1 (10000-1)
assert(index>= 0);
}
