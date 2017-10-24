#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Neuron.hpp"
#include "Excitatory.hpp"
#include "Inhibitory.hpp"
#include <vector>
#include <array>


class Inhibitory;
class Excitatory;
class Network{
	private:
	
		std::vector<Neuron*> my_network; 
		std::array<std::array<bool, Inhibitory::nb_inhib+Excitatory::nb_excit>, Inhibitory::nb_inhib+Excitatory::nb_excit> targets; 
		std::array<std::array<double ,Inhibitory::nb_inhib+Excitatory::nb_excit> ,Inhibitory::nb_inhib+Excitatory::nb_excit> current_weights; 
		
	public:
	
	//Constructeur et destructeur
		Network();
		~Network();
		
	//Getters
	std::vector<Neuron*> getNetwork() const;
	std::array<std::array<double,  Inhibitory::nb_inhib+Excitatory::nb_excit> , Inhibitory::nb_inhib+Excitatory::nb_excit> getCurrentWeights() const;
		
	//Connexion
	void connect(unsigned int from, unsigned int to, double weight, double ext_current, unsigned int time);
	
};

#endif
