#include "Network.hpp"
#include <random>
#include <cassert>
#include <iostream>
#include <fstream>


/**
 * Constructor
*/
Network::Network()
{
	
	for(long unsigned int i(0); i <(Network::nb_neurons_); ++i){
		Neuron n(i);
		my_network_.push_back(n);
	}
	
	
	for(unsigned int i(0); i<nb_excit_; ++i){
		targets_.push_back(std::vector<unsigned int> (Cei_,0));
		weights_.push_back(0.1);
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
			assert(i<nb_excit_);
			assert(j<Ce_);
			targets_[i][j]=dis_e(gen);
		}
	}
	for(unsigned int i(nb_excit_); i< nb_neurons_; ++i){
		targets_.push_back(std::vector<unsigned int> (Cei_,0));
		weights_.push_back(-(0.1*Neuron::g_));
		for(unsigned int j(Ce_); j< Network::Cei_; ++j){
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
			assert(i<nb_neurons_);
			assert(i>=nb_excit_);
			assert(j>=Ce_);
			assert(j<Cei_);
			targets_[i][j]=dis_e(gen);
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

void Network::update_all(unsigned int time){
	std::ofstream out("spikes.txt", std::ios_base::app);
	if (out.fail()){
		std::cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat" << "en écriture." << std::endl;
	}else{ 
		for(unsigned int i(0); i<Network::nb_neurons_; ++i){
			assert(i< nb_neurons_);
			if(my_network_[i].update(0, time)){ //If the neuron i has spiked
				assert(my_network_[i].getSpikesNumber()>0);
				out << time*Neuron::h_  << '\t' << my_network_[i].getIndex() << '\n';
				/*! \brief set in the buffer the incoming spikes, @ see Neuron::incoming_spikes_
				*/
				for(unsigned int j(0); j<targets_[i].size();++j){
					assert(j<targets_[i].size());
					assert(i<weights_.size());
					my_network_[targets_[i][j]].receive_spikes(weights_[i]);
				}
			}
		}
	}
}

void Network::launchSimulation(unsigned int steps_number){
	for(unsigned int t(1); t<steps_number; ++t){
			/*! \brief There is no update when the time is equal to 0
			*/
			update_all(t);
							
	} 
	
}

