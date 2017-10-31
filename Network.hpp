#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Neuron.hpp"
#include <vector>

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
		static constexpr unsigned int Ce_=0.1*nb_excit_; /**< Ce_ = Number of excitatory connexion of one neuron -> nb_excit_*10%=1000 */
		static constexpr unsigned int Ci_=0.1*nb_inhib_; /**< Ci_ = Number of excitatory connexion of one neuron -> nb_inhib_*10%=250 */
		static constexpr unsigned int Cei_=Ce_+Ci_; /**< Cei_ = Number of connexion of one neuron -> Ce_+Ci_=1250 */
	
		/**
		 * Constructor
		 * creates all the connection between the neurons,
		 * it asscribes the amplitude of the postsynaptic currrent corresponding to the nature of the neuron (excitatory or inhibitory),
		 * and set random connexions (2500 inhibitory and 10000 excitatory) following an uniform distibution 
		*/
		Network();
			
		/**
		 * Getter
		 * @return the connexion of a neuron
		*/
		std::vector<unsigned int> getTargets(unsigned int index) const;
		
		void update_all(unsigned int time);
		void launchSimulation(unsigned int steps_number);
	
	private:
	
		std::vector<Neuron> my_network_; /**< my_network_ corresponds to a tab with the indices of all my neurons 
		
		/**
		 * targets_ is a tab containing the number of time neurons are connected to one another, 
		 * for example, targets_[from][to]=2, the neuron(to) is a target of neuron(from) with two connexions
		*/
		std::vector<std::vector<unsigned int>> targets_; 
		std::vector<double> weights_;
	
};

#endif
