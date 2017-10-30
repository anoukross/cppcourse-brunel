#include "Network.hpp"
#include <random>
#include <cassert>
#include <iostream>

/**
 * Constructor
*/
Network::Network()
{
	
	for(unsigned int i(0); i < nb_neurons_ ; ++i){
		/*! \brief Each compartment of network corresponds to the indices of my neurons
		*/
		my_network_.push_back(i);
	}
	
	
	for(unsigned int i(0); i<nb_excit_; ++i){
		targets_.push_back(std::vector<unsigned int> (Cei_,0));
		for(unsigned int j(0); j< Network::Ce_; ++j){
			/**initialization of the amplitude of the postsynaptic current (J=0.1mV) of the excitatory  neurons 
			 * The excitatory are the first 10000 elements of my_network
			 * Creates the excitatory connexion of the neuron i
			*/
			/*! \brief Creation of a random device
			*/
			static std::random_device rd;
			static std::mt19937 gen(rd());
	
			/*! \brief The random generator follows a uniform distribution with the numbers 0 - nb_excit_-1(=9999)
			*/
			static std::uniform_int_distribution<> dis_e(0, nb_excit_-1);
			/*! \brief Creates randomly the connexion that neuron with index i receives from excitatory neurons (Ce_=1000)
			*/
			connect(i, dis_e(gen) , j);
		}
	}
	for(unsigned int i(nb_excit_); i< nb_neurons_; ++i){
		targets_.push_back(std::vector<unsigned int> (Cei_,0));
		for(unsigned int j(0); j< Network::Ci_; ++j){
			/**initialization of the amplitude of the postsynaptic current (J=0.5mV) of the inhibitory  neurons 
			* The inhibitory are the last 2500 elements of my_network
			* creates the inhibitory connexion of neuron i
			*/

			/*! \brief Creation of a random device
			*/
			static std::random_device rd;
			static std::mt19937 gen(rd());
	
			/*! \brief The random generator follows a uniform distribution with the numbers 0 - nb_excit_-1(=9999)
			*/
			static std::uniform_int_distribution<> dis_e(nb_excit_, nb_neurons_-1);
			/*! \brief Creates randomly the connexion that neuron with index i receives from excitatory neurons (Ce_=1000)
			*/
			connect(i, dis_e(gen), j);
	}
	
	
	}
}

/**
* Getters
*/


std::vector<unsigned int> Network::getTargets(unsigned int index) const{
	/*! \brief Check connexion of a neuron
	*/
	assert(index<targets_.size());
	return targets_[index];
}

/**
* Initialisation of targets and weights
*/

void Network::connect(unsigned int from, unsigned int to, unsigned int index){
	assert(from<nb_neurons_);
	assert(to<nb_neurons_);
	
	targets_[from][index]=to;
	
}

