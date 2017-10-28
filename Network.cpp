#include "Network.hpp"
#include <random>
#include <cassert>

/**
 * Constructor
*/
Network::Network()
{
	for(unsigned int i(0); i < nb_neurons_ ; ++i){
		for(unsigned int j(0); j < nb_neurons_ ; ++j){
			/*! \brief Initialize all the  connexions at 0 -> not connected
			*/
			targets_[i][j]=0; 
		}
		/*! \brief Each compartment of network corresponds to the indices of my neurons
		*/
		my_network_[i]=i;
	}
	double ex_weight(0.1); //PAS BIEN POUR ENCAPSULATION
	double in_weight(0.5);
	for(unsigned int i(0); i<nb_excit_; ++i){
		for(unsigned int j(0); j< nb_neurons_; ++j){
			/**initialization of the amplitude of the postsynaptic current (J=0.1mV) of the excitatory  neurons 
			 * The excitatory are the first 10000 elements of my_network
			*/
			current_weights_[i][j]=ex_weight;
		}
	}
	for(unsigned int i(nb_excit_); i< nb_neurons_; ++i){
		for(unsigned int j(0); j< nb_neurons_; ++j){
			/**initialization of the amplitude of the postsynaptic current (J=0.5mV) of the inhibitory  neurons 
			* The inhibitory are the last 2500 elements of my_network
			*/
			current_weights_[i][j]=in_weight;
		}
	}
	
	/*! \brief Creation of a random device
	*/
	std::random_device rd;
	std::mt19937 gen(rd());
	
	/*! \brief The random generator follows a uniform distribution with the numbers 0 - nb_excit_-1(=9999)
	*/
	std::uniform_int_distribution<> dis_e(0, nb_excit_-1);
	/*! \brief Creates randomly the connexion that neuron with index i receives from excitatory neurons (Ce_=1000)
	*/
	for(unsigned int i(0); i<nb_neurons_; ++i){
		for(unsigned int j(0); j<Neuron::Ce_; ++j){
			assert(dis_e(gen)<=(nb_excit_-1));
			assert(dis_e(gen)<=targets_.size());
			targets_[dis_e(gen)][i]+=1;
		}
	}
	

	/*! \brief The random generator follows a uniform distribution with the numbers nb_excit_(10000) - nb_neurons_-1(12500-1)
	*/
	std::uniform_int_distribution<> dis_i((nb_excit_), nb_neurons_-1); //Creates randomly the connexion that neuron i receives -> 250 inhibitory
	for(unsigned int i(0); i<nb_neurons_; ++i){
	/*! \brief Creates randomly the connexion that neuron with index i receives from inhibitory neurons (Ci_=250)
	*/
		for(unsigned int j(0); j<Neuron::Ci_; ++j){
			assert(dis_e(gen)<=(nb_neurons_-1));
			assert(dis_i(gen)<=targets_.size());
			targets_[dis_i(gen)][i]+=1;
		}
	}
	
	
}

/**
* Getters
*/
std::array<std::array<double ,Network::nb_neurons_>, Network::nb_neurons_> Network::getCurrentWeights() const{
	return current_weights_;
}

unsigned int Network::getTargets(unsigned int from, unsigned int to) const{
	/*! \brief Check if n from is connected to n to
	*/
	return targets_[from][to];
}




