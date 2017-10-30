#include "Neuron.hpp"
#include "Excitatory.hpp"
#include "Inhibitory.hpp"
#include "Network.hpp"
#include <iostream>
#include <array>
#include <fstream>
#include <cassert>

using namespace std;

/**
 * The main program
*/

int main(){
	Network net; /**< created a network composed 12500 neurons, @see Network  */
	
	
	vector<Neuron> all_neurons; /**< creation of a tab which will contain the neurons  */
	
	for(long unsigned int i(0); i <(Network::nb_excit_); ++i){
		Excitatory e(i);
		all_neurons.push_back(e);
	}
	
	for(long unsigned int i(Network::nb_excit_); i <(Network::nb_neurons_); ++i){
		Inhibitory e(i);
		all_neurons.push_back(e);
	}
	
	double I(0); /**< External current I = 0pA  */
	
	double start_time(0.0); /**< The beggining of the simulation time */
	double stop_time(0.0); /**< The end of the simulation time */
	

	cout << "Choose the stop time: ";
	cin >> stop_time;
	cout << endl;
	
	
	ofstream out("spikes.txt"); /**< will write and create if necessary on a file simulator.txt */
	unsigned int steps_number(stop_time/Neuron::h_); /**< steps_number corresponds to the stop time dividedby h to get an integer */
	
		for(unsigned int t(start_time/Neuron::h_); t<steps_number; ++t){
			/*! \brief Check if the opening of the file goes well
			*/
			if (out.fail()){
				cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat"
				<< "en écriture." << endl;
			/*! \brief There is no update when the time is equal to 0
			*/
			} else if (t>0) {
				for(unsigned int i(0); i<Network::nb_neurons_; ++i){
					assert(i<all_neurons.size());
					if(all_neurons[i].update(I, t)){ //If the neuron i has spiked
						assert(all_neurons[i].getSpikesNumber()>0);
						out << t*Neuron::h_  << '\t' << i << '\n';
							/*! \brief set in the buffer the incoming spikes, @ see Neuron::incoming_spikes_
							*/
							
							for(unsigned int j(0); j<net.getTargets(i).size();++j){
								assert(j<net.getTargets(i).size());
								all_neurons[net.getTargets(i)[j]].receive_spikes(all_neurons[i].getWeight());
							}
					}
						
						

						//out << "A temps: " << t*Neuron::h_ << " ms, le potentiel de membrane du neurone " << i <<  " est: " << all_neurons[i].getPotential() << "." << '\n';
					
				}
			}
		} 
	
	
	return 0;
	
}
