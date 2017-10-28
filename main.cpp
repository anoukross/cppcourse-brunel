#include "Neuron.hpp"
#include "Excitatory.hpp"
#include "Inhibitory.hpp"
#include "Network.hpp"
#include <iostream>
#include <array>
#include <fstream>

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
	
	
	ofstream out("simulator.txt"); /**< will write and create if necessary on a file simulator.txt */
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
					for(unsigned int j(0); j<Network::nb_neurons_; ++j){
						unsigned int connected_to(net.getTargets(i,j)); /**< connect_to corresponds to the number of time nj is a target of ni */
						/*! \brief check whether ni has spikes and if nj is a target of ni
						*/
							if(all_neurons[i].update(I, t) and connected_to>0){ 
								for(unsigned int a(0); a<connected_to; ++a){
									/*! \brief set in the buffer the incoming spikes, @ see Neuron::incoming_spikes_
									*/
									all_neurons[j].receive_spikes(net.getCurrentWeights()[i][j]); 
									/*! \brief j is gets the connect from neuron i according to  the number connected_to
									*/
									all_neurons[j].update(I, t); 
								} 
							}
						
						
					}
				
					//out << "A temps: " << t*Neuron::h << " ms, le potentiel de membrane du neurone " << i+1 <<  " est: " << all_neurons[i].getPotential() << "." << endl;
				}
			}
		}
	
	
	return 0;
	
}
