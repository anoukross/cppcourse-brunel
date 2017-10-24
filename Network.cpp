#include "Network.hpp"
#include <random>
#include <iostream>
#include <cassert>

//Constructeur et destructeur

Network::Network()
{
	for(unsigned int e(0); e<Excitatory::nb_excit; ++e){
		Excitatory* ne(nullptr);
		ne = new Excitatory(); 
		my_network.push_back(ne);
		double weight(my_network[0]->getWeight());
		for(unsigned int i(0); i<Excitatory::nb_excit; ++i){
			for(unsigned int j(0); j<Excitatory::nb_excit; ++j){
			targets[i][j]=false; //Initialise toute les connexions à fausse
			current_weights[i][j]=weight;
			}
		}
		
	}
	
	for(unsigned int e(0); e<Inhibitory::nb_inhib; ++e){
		Inhibitory* ni(nullptr);
		ni = new Inhibitory(); 
		my_network.push_back(ni);
		double weight(my_network[Excitatory::nb_excit]->getWeight());
		for(unsigned int i(0); i<Inhibitory::nb_inhib; ++i){
			for(unsigned int j(0); j<Inhibitory::nb_inhib; ++j){
			targets[i][j]=false; //Initialise toute les connexions à fausse
			current_weights[i][j]=weight;
			}
		}
		
	}
	
	std::random_device rd;
	std::mt19937 gen(rd());
	
	std::uniform_int_distribution<> dis_e(0, Excitatory::nb_excit-1); //Creates randomly the connexion that neuron i receives ->1000 excitatory
	for(unsigned int i(0); i<my_network.size(); ++i){
		for(unsigned int j(0); j<Neuron::Ce; ++j){
			assert(dis_e(gen)<=(Excitatory::nb_excit-1));
			assert(dis_e(gen)<=targets.size());
			targets[dis_e(gen)][i]=true;
		}
	}
	

	
	std::uniform_int_distribution<> dis_i((Excitatory::nb_excit), my_network.size()-1); //Creates randomly the connexion that neuron i receives -> 250 inhibitory
	for(unsigned int i(0); i<my_network.size(); ++i){
		for(unsigned int j(0); j<Neuron::Ci; ++j){
			assert(dis_e(gen)<=(my_network.size()-1));
			assert(dis_i(gen)<=targets.size());
			targets[dis_i(gen)][i]=true;
		}
	}
	
	
}

Network::~Network(){
	for (unsigned int i(0); i<my_network.size(); ++i){
 		delete my_network[i];
		my_network[i]=nullptr;
 	}
	my_network.clear();
}

//Getters
std::vector<Neuron*> Network::getNetwork() const{
	return my_network;
}
std::array<std::array<double ,  Inhibitory::nb_inhib+Excitatory::nb_excit> , Inhibitory::nb_inhib+Excitatory::nb_excit > Network::getCurrentWeights() const{
	return current_weights;
}


//Connexion
void Network::connect(unsigned int from, unsigned int to, double weight, double ext_current, unsigned int time){
	if((my_network[from]->update(ext_current, time)) and (targets[from][to])){ // check whether n(from) has spikes and if it transmits his amplitude to n(to)
		my_network[to]->receive_spikes((my_network[to]->getDelay()),weight); //set in the buffer the incoming spikes
		my_network[to]->update(ext_current, time); //When the spike is transmitted the external current is equal to 0
			
	}
}


