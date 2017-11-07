#include "Network.hpp"
#include <random>
#include <cassert>

/**
 * Constructor
*/
Network::Network()
{
	/**
	 * Creation of the neurons of my network
	 */
	for(long unsigned int i(0); i<nb_neurons_; ++i){
		Neuron n(i);
		my_network_.push_back(n);
	}
	double excit_weight(Neuron::je_);
	/**
	 * creation of two random uniform_int distribution
	 * The first one going from 0 to nb_excit_-1 -> corresponds to the excitatory connexion
	 * The second to nb_excit_ to nb_neurons_-1 -> corresponds to the inhibitory connexion
	 */
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis_e(0, nb_excit_-1);
	static std::uniform_int_distribution<> dis_i(nb_excit_, nb_neurons_-1);
	for (long unsigned int i(0); i <nb_neurons_; ++i){

	/** \brief add in target a vector of size nb_connex_ with 0 in every box
	 */
		connexions_.push_back(std::vector<unsigned int> (nb_connex_,0));
		if(i<nb_excit_){
			/**initialization of the amplitude of the postsynaptic current (je_=0.1mV) of the excitatory neurons
			 * The excitatory are the first 10000 elements of my_network_
			 */
			weights_.push_back(excit_weight);
			for(unsigned int j(0); j< nb_connex_excit_; ++j){
				assert(i<nb_excit_);
				assert(j<connexions_[i].size());
				/**
				 * Creates randomly the connexion that neuron with index i receives from excitatory neurons
				 * targets_[i][j] means that neuron i is a target of neuron j
				*/
				unsigned int random_index(dis_e(gen));
				connexions_[i][j]=random_index;

				/**
				 * add the index i to the outcoming_connexions_ tab of neuron j
				 */
				my_network_[random_index].setOutcomingConnexions(i);
			}
		}else{
			/**initialization of the amplitude of the postsynaptic current (ji_=g_*je_ =-0.5mV) of the inhibitory neurons
			 * The inhibitory  are the last 2500 elements of my_network_
			 */
			weights_.push_back(-(excit_weight*Neuron::g_));
			for(unsigned int j(nb_connex_excit_); j<nb_connex_; ++j){
				assert(i<connexions_.size());
				assert(i>=nb_excit_);
				assert(j>=nb_connex_excit_);
				assert(j<connexions_[i].size());
				/**
				 * Creates randomly the connexion that neuron with index i receives from inhibitory neurons
				 * targets_[i][j] means that neuron i is a target of neuron j
				*/
				unsigned int random_index(dis_i(gen));
				connexions_[i][j]=random_index;

				/**
				 * add the index i to the outcoming_connexions_ tab of neuron j
				 */
				my_network_[random_index].setOutcomingConnexions(i);

			}
		}
	}
	assert(connexions_.size()==nb_neurons_);
	assert(connexions_[0].size()==nb_connex_);
	assert(my_network_.size()==nb_neurons_);
	assert(weights_.size()==nb_neurons_);

}

/**
* Getters
*/
Neuron Network::getNeuron(unsigned int index) const{
	assert(index<my_network_.size());
	return my_network_[index];
}
std::vector<unsigned int> Network::getConnexions(unsigned int index) const{
	/** \brief returns the indices of the neurons that target the neuron with index index
	*/
	assert(index<connexions_.size());
	return connexions_[index];
}

double Network::getWeight(unsigned int index) const{
	/** \brief returns the weights that neuron with index index sends to its targets
	*/
	assert(index<weights_.size());
	return weights_[index];
}

/**
* Update of the network
*/

std::vector<unsigned int> Network::update(unsigned int time){
	std::vector<unsigned int> index_of_spikers; /**< contains the index of the neurons that spikes at this time, if this time is a multiple of 10 -> if h_ is an integer in ms*/
	for(unsigned int i(0); i<Network::nb_neurons_; ++i){
		assert(i<nb_neurons_);
		if(my_network_[i].update(0, time)){ /**< check whether neuron i has spiked*/
			assert(my_network_[i].getSpikesNumber()>0);
			if(time%10==0){ /**< sampling of the values every 10 seconds*/
				index_of_spikers.push_back(i);
			}
			std::vector<unsigned int> outcoming_connex(my_network_[i].getOutcomingConnexions()); /**< tab containing all the target of neuron i */
				if(!outcoming_connex.empty()){ /**<To verify that neuron i targets other neurons */
					for(unsigned int j(0); j<outcoming_connex.size();++j){
						assert(j<outcoming_connex.size());
						assert(i<weights_.size());
						sendSpikes(outcoming_connex[j],weights_[i]); /**< call sendSpikes so that neuron j(target of neuron i) can receive the pps weight from neuron i */
					}
				}
		}
	}
	return index_of_spikers;
}
/**
 * SendSpikes
 */

void Network::sendSpikes(unsigned int to, double weight){
	/**
	 * call receiveSpikes to the neuron to that receives pps weight from the neuron from
	 * @see Neuron::receiveSpikes(double weight)
	 */
	 assert(to<nb_neurons_);
	my_network_[to].receiveSpikes(weight);
}


