#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Neuron.hpp"
#include <vector>

/**
* The class Networks manages the interaction between the neurons
*/

class Network{

	public:
		/**
		 * static constant of the class Network, need to be accessible from outside, no getters because cannot have static methods that are const
		*/

		static constexpr long unsigned int nb_excit_ = 10000; /**< nb_excit_ corresponds to the number of excitatory neurons in a network */
		static constexpr long unsigned int nb_inhib_ = 2500; /**< nb_inhib_ corresponds to the number of inhibitory neurons in a network */
		static constexpr long unsigned int nb_neurons_= nb_inhib_ + nb_excit_; /**< nb_inhib_ corresponds to the number of neurons in a network */
		static constexpr unsigned int nb_connex_excit_=0.1*nb_excit_; /**< nb_connex_excit_ = Number of excitatory connexion of one neuron -> nb_excit_*10%=1000 */
		static constexpr unsigned int nb_connex_inhib_=0.1*nb_inhib_; /**< nb_connex_inhib_ = Number of inhibitory connexion of one neuron -> nb_inhib_*10%=250 */
		static constexpr unsigned int nb_connex_=nb_connex_excit_+ nb_connex_inhib_; /**< nb_connex_ = Number of connexion of one neuron -> nb_connex_excit_+nb_connex_inhib_=1250 */

		/**
		 * Constructor
		 * creates all the connection between the neurons,
		 * set random connexions (2500 inhibitory and 10000 excitatory) following an uniform distribution
		 * it assigns the amplitude of the postsynaptic weight corresponding to the nature of the neuron (excitatory or inhibitory)
		 *@see targets_
		 *@see weights_
		*/
		Network();

		/** \brief Getters
		*/
		/**
		 * @return the neuron with index index
		 * @param index, index of the neuron
		 */
		Neuron getNeuron(unsigned int index) const;

		/**
		 *@return the indices of the neurons that target neuron with index index
		 * @param index corresponds to the index of a neuron of my network
		 */
		std::vector<unsigned int> getConnexions(unsigned int index) const;

		/**
		 *@return the weight that the neurons with index index sends to its targets
		 * @param index corresponds to the index of a neuron of my network
		 */
		double getWeight(unsigned int index) const;

		/**
		 * The update method of my network
		 * call Neuron::update for each neuron of my network
		 * and send the pps weight to the targets of the neurons that spikes
		 * @return a tab containing the indices of the neurons that spikes at this particular step of time t
		 * @param time of the simulation in step of time ->*0.1 to get it in ms
		 */
		std::vector<unsigned int> update(unsigned int time);

		/**
		 * @param to, the index of the neuron that receives the pps weight
		 * @param weight the weight of the neuron that sends the spikes
		 * 0.1 for the excitatory and -0.5 for the inhibitory
		 * sendSpikes call Neuron::receiveSpikes of the neuron to with the weight weight
		 */
		void sendSpikes(unsigned int to, double weight);

	private:
		/** \brief Attribute
		 */
		std::vector<Neuron> my_network_; /**< my_network_ corresponds to a tab with all my neurons, index of a neuron corresponds to its position in the tab */

		/**
		 * targets_ is a tab containing the connexions of all the neurons of a network
		 * the line targets_[i] contains the indices of all the neurons that send postsynaptic weight to neuron i
		*/
		std::vector<std::vector<unsigned int>> targets_;

		/**
		 * weight_ is a tab containing the weight associated with all my neurons
		 * the line weights[i] contains the weight that the neuron i send to his targets
		 * weights[0] to weights[9999] =je_
		 * weights[10000] to weights[12499]=ji_=-g_*je_
		*/
		std::vector<double> weights_;

};

#endif
