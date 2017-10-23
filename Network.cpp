#include "Network.hpp"
#include <random>

//Constructeur et destructeur

Network::Network()
{
	for(unsigned int e(0); e<Excitatory::nb_excit; ++e){
		Excitatory* ne(nullptr);
		ne = new Excitatory(); 
		my_network.push_back(ne);
		
		for(unsigned int i(0); i<Excitatory::nb_excit; ++i){
			targets.emplace_back(); 
			targets[i].push_back(false); //Initialise toute les connexions à fausse
			current_weights.emplace_back();
			current_weights[i].push_back(my_network[i]->getWeight());
			delay.emplace_back();
			delay[i].push_back(15); //...
		}
		
	}
	
	for(unsigned int e(0); e<Inhibitory::nb_inhib; ++e){
		Inhibitory* ne(nullptr);
		ne = new Inhibitory(); 
		my_network.push_back(ne);
		
		for(unsigned int i(0); i<Inhibitory::nb_inhib; ++i){
			targets.emplace_back(); 
			targets[i].push_back(false); //Initialise toute les connexions à fausse
			current_weights.emplace_back();
			current_weights[i].push_back(my_network[i]->getWeight());
			delay.emplace_back();
			delay[i].push_back(15); //...
		}
		
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	
	std::uniform_int_distribution<> dis_e(0, Excitatory::nb_excit); //Creates randomly the connexion that neuron i receives ->1000 excitatory
	for(unsigned int i(0); i<my_network.size(); ++i){
		for(unsigned int j(0); j<Neuron::Ce; ++j){
			targets[dis_e(gen)][i]=true;
		}
	}
	
	std::uniform_int_distribution<> dis_i((Excitatory::nb_excit+1), Inhibitory::nb_inhib); //Creates randomly the connexion that neuron i receives -> 250 inhibitory
	for(unsigned int i(0); i<my_network.size(); ++i){
		for(unsigned int j(0); j<Neuron::Ci; ++j){
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
std::vector<std::vector<double>> Network::getCurrentWeights() const{
	return current_weights;
}


//Connexion
void Network::connect(unsigned int from, unsigned int to, double weight, double ext_current, unsigned int time){
	if((my_network[from]->update(ext_current, time)) and (targets[from][to])){ // check whether n(from) has spikes and if it transmits his amplitude to n(to)
		my_network[to]->receive_spikes((delay[from][to]),weight); //set in the buffer the incoming spikes
		my_network[to]->update(ext_current, time); //When the spike is transmitted the external current is equal to 0
			
	}
}


