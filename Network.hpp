#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Neuron.hpp"
#include "Excitatory.hpp"
#include "Inhibitory.hpp"
#include <array>

/**
* Predefinition of the classes Inhibitory and Excitatory
*/
class Inhibitory;
class Excitatory;

/**
* The class Networks manages the interaction between the neurons
*/

class Network{

	public:
		/**
		 * static constant of the class Network, need to be accessible from outside, no getters becuase cannot have const static methods
		*/
		
		static constexpr long unsigned int nb_excit_ = 10000; /**< nb_excit_ corresponds to the number of excitatory neurons in a network */
		static constexpr long unsigned int nb_inhib_ = 2500; /**< nb_inhib_ corresponds to the number of inhibitory neurons in a network */
		static constexpr long unsigned int nb_neurons_= nb_inhib_ + nb_excit_; /**< nb_inhib_ corresponds to the number of neurons in a network */
	
		/**
		 * Constructor
		 * creates all the connection between the neurons,
		 * it asscribes the amplitude of the postsynaptic currrent corresponding to the nature of the neuron (excitatory or inhibitory),
		 * and set random connexions (2500 inhibitory and 10000 excitatory) following an uniform distibution 
		*/
		Network();
			
		/**
		 * Getter 
		 * current_weights_ is a tab with the amplitude of the postsynaptic current corresponding to each pair of neuron [i][j]
		 * if i is inhibitory, current_weights_[i][j] =0.5 mV, if i is excitatory current_weights_[i][j]=0.1mV
		 * @return current_weights_
		*/
		std::array<std::array<double ,nb_neurons_>, nb_neurons_> getCurrentWeights() const; 
		
		/**
		 * Getter
		 * @return targets_ the number of time the neuron(to) receives postsynaptic current from neuron(from)
		*/
		unsigned int getTargets(unsigned int from, unsigned int to) const;
	
	private:
	
		std::array<unsigned int, nb_neurons_> my_network_; /**< my_network_ corresponds to a tab with the indices of all my neurons */
		
		/**
		 * targets_ is a tab containing the number of time neurons are connected to one another, 
		 * for example, targets_[from][to]=2, the neuron(to) is a target of neuron(from) with two connexions
		*/
		std::array<std::array<unsigned int, nb_neurons_>, nb_neurons_> targets_; 
		
		/**
		 * current_weights_ is a tab with the amplitude of the postsynaptic current corresponding to each pair of neuron [from][to]
		 * if neuron(from) is inhibitory, current_weights_[from][to] =0.5 mV
		 *  if neuron(from) is excitatory current_weights_[from][to]=0.1mV 
		*/
		std::array<std::array<double ,nb_neurons_>, nb_neurons_> current_weights_;
	
};

#endif
