#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Neuron.hpp"
#include "Excitatory.hpp"
#include "Inhibitory.hpp"
#include <vector>



class Network{
	private: 
	
		std::vector<Neuron*> my_network; 
		std::vector<std::vector<bool>> targets; 
		std::vector<std::vector<double>> current_weights; 
		std::vector<std::vector<unsigned int>> delay;
		
	public:
	
	//Constructeur et destructeur
		Network();
		~Network();
		
	//Getters
	std::vector<Neuron*> getNetwork() const;
	std::vector<std::vector<double>> getCurrentWeights() const;
		
	//Connexion
	void connect(unsigned int from, unsigned int to, double weight, double ext_current, unsigned int time);
	
};

#endif
