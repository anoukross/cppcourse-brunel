#include "Neuron.hpp"
#include "Excitatory.hpp"
#include "Inhibitory.hpp"
#include "Network.hpp"
#include <iostream>
#include <array>
#include <fstream>

using namespace std;

int main(){
	Network net;
	
	vector<Neuron> all_neurons;
	
	for(long unsigned int i(0); i <(Network::nb_excit_); ++i){
		Excitatory e(i);
		all_neurons.push_back(e);
	}
	
	for(long unsigned int i(Network::nb_excit_); i <(Network::nb_neurons_); ++i){
		Inhibitory e(i);
		all_neurons.push_back(e);
	}
	
	double I(0); // External current (I=[0,400 pA])
	
	double startTime(0.0);
	double stopTime(0.0);
	

	cout << "Choose the stop time: ";
	cin >> stopTime;
	cout << endl;
	
	
	ofstream out("simulator.txt");
	unsigned int steps_number(stopTime/Neuron::h_); //Division by h to get an integer
	
		for(unsigned int t(startTime/Neuron::h_); t<steps_number; ++t){
			if (out.fail()){
				cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat"
				<< "en écriture." << endl;
			} else if (t>0) { //There is no update when the time is equal to 0
				for(unsigned int i(0); i<all_neurons.size(); ++i){
					for(unsigned int j(0); j<all_neurons.size(); ++j){
						unsigned int connected_to(net.getTargets(i,j));
							if(all_neurons[i].update(I, t) and connected_to>0){ // check whether ni has spikes and if nj is a target of ni
								for(unsigned int a(0); a < connected_to; ++a){
									all_neurons[j].receive_spikes(net.getCurrentWeights()[i][j]); //set in the buffer the incoming spikes
									all_neurons[j].update(I, t); //When the spike is transmitted the external current is equal to 0
								} //Connect to the neurons the number of time it is connected
							}
						
						
					}
				
					//out << "A temps: " << t*Neuron::h << " ms, le potentiel de membrane du neurone " << i+1 <<  " est: " << all_neurons[i].getPotential() << "." << endl;
				}
			}
		}
	
	
	return 0;
	
}
