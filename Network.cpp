#include "Network.hpp"
#include <random>
#include <cassert>

//Constructeur et destructeur

Network::Network()
{
	for(unsigned int i(0); i < nb_neurons_ ; ++i){
		for(unsigned int j(0); j < nb_neurons_ ; ++j){
			targets_[i][j]=0; //Initialise toute les connexions à 0 -> pas connecté
		}
		my_network_[i]=i;
	}
	double ex_weight(0.1); ///PAS BIEN POUR ENCAPSULATION
	double in_weight(0.5);
	for(unsigned int i(0); i<nb_excit_; ++i){
		for(unsigned int j(0); j< nb_neurons_; ++j){
		current_weights_[i][j]=ex_weight;
		}
	}
	for(unsigned int i(nb_excit_); i< nb_neurons_; ++i){
		for(unsigned int j(0); j< nb_neurons_; ++j){
		current_weights_[i][j]=in_weight;
		}
	}
	
	std::random_device rd;
	std::mt19937 gen(rd());
	
	std::uniform_int_distribution<> dis_e(0, nb_excit_-1); //Creates randomly the connexion that neuron i receives ->1000 excitatory
	for(unsigned int i(0); i<nb_neurons_; ++i){
		for(unsigned int j(0); j<Neuron::Ce_; ++j){
			assert(dis_e(gen)<=(nb_excit_-1));
			assert(dis_e(gen)<=targets_.size());
			targets_[dis_e(gen)][i]+=1;
		}
	}
	

	
	std::uniform_int_distribution<> dis_i((nb_excit_), nb_neurons_-1); //Creates randomly the connexion that neuron i receives -> 250 inhibitory
	for(unsigned int i(0); i<nb_neurons_; ++i){
		for(unsigned int j(0); j<Neuron::Ci_; ++j){
			assert(dis_e(gen)<=(nb_neurons_-1));
			assert(dis_i(gen)<=targets_.size());
			targets_[dis_i(gen)][i]+=1;
		}
	}
	
	
}

std::array<std::array<double ,Network::nb_neurons_>, Network::nb_neurons_> Network::getCurrentWeights() const{
	return current_weights_;
}

unsigned int Network::getTargets(unsigned int from, unsigned int to) const{
	return targets_[from][to]; //Check if n from is connected to n to
}




