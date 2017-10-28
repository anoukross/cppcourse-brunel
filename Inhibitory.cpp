#include "Inhibitory.hpp"
#include <cassert>

//Constructeur et destructeur

Inhibitory::Inhibitory(unsigned int index)
:Neuron(index, 0.5) //Je = 0.5mV
{
assert(index > 9999);  //The index of the inhibitory neuron should be between nb_excit(10000) to nb_neurons -1 (12500-1)
assert(index < 12500); 
}
