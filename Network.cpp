#include "Network.hpp"
#include <random>
#include <cassert>



/**
 * Constructor
*/
Network::Network()
{
	for(long unsigned int i(0); i<nb_neurons_; ++i){
		Neuron n(i);
		my_network_.push_back(n);
	}
	double excit_weight(Neuron::getWeight());
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis_e(0, nb_excit_-1);
	static std::uniform_int_distribution<> dis_i(nb_excit_, nb_neurons_-1);
	for (long unsigned int i(0); i <nb_neurons_; ++i){
		targets_.push_back(std::vector<unsigned int> (nb_connex_,0));
		if(i<nb_excit_){
			weights_.push_back(excit_weight);
			for(unsigned int j(0); j< nb_connex_excit_; ++j){
			/**initialization of the amplitude of the postsynaptic current (J=0.1mV) of the excitatory  neurons 
			 * The excitatory are the first 10000 elements of my_network
			 * Creates the excitatory connexion of the neuron i
			/*! \brief Creates randomly the connexion that neuron with index i receives from excitatory neurons (Ce_=1000)
			*/
				assert(i<nb_excit_);
				assert(j<nb_connex_excit_);
				targets_[i][j]=dis_e(gen);
				my_network_[j].setOutcomingConnexion(i);
			}
		}else{
			weights_.push_back(-(excit_weight*Neuron::get_g()));
			for(unsigned int j(nb_connex_excit_); j<nb_connex_; ++j){
			/**initialization of the amplitude of the postsynaptic current (J=0.5mV) of the inhibitory  neurons 
			* The inhibitory are the last 2500 elements of my_network
			* creates the inhibitory connexion of neuron i
			*/
				assert(i<nb_neurons_);
				assert(i>=nb_excit_);
				assert(j>=nb_connex_excit_);
				assert(j<nb_connex_);
				targets_[i][j]=dis_i(gen);
				my_network_[j].setOutcomingConnexion(i);
	
			}
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

double Network::getWeight(unsigned int index) const{
	assert(index<weights_.size());
	return weights_[index];
}

/**
* Initialisation of targets and weights
*/

std::vector<unsigned int> Network::update(unsigned int time){
	std::vector<unsigned int> index_of_spikers;
	for(unsigned int i(0); i<Network::nb_neurons_; ++i){
		assert(i< nb_neurons_);
		if(my_network_[i].update(0, time)){ //If the neuron i has spiked
			assert(my_network_[i].getSpikesNumber()>0);
			if(time%10==0){
				index_of_spikers.push_back(i);
				/*! \brief set in the buffer the incoming spikes, @ see Neuron::incoming_spikes_
				*/
			}
			std::vector<unsigned int> outcoming_connex(my_network_[i].getOutcomingConnexion());
			for(unsigned int j(0); j<outcoming_connex.size();++j){
				assert(j<outcoming_connex.size());
				assert(i<weights_.size());
				sendSpikes(outcoming_connex[j],weights_[i]);
			}
		}
	}
	return index_of_spikers;
}

void Network::sendSpikes(unsigned int to, double weight){
	my_network_[to].receiveSpikes(weight);
}


