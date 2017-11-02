#include "Experiment.hpp"
#include <iostream>
#include <fstream>
#include <vector>

void Experiment::launchSimulation(unsigned int time){
	time*=10;
	std::ofstream out("spikes.txt");
	Network net;
	if (out.fail()){
		std::cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat" << "en écriture." << std::endl;
	}else{
		for(unsigned int t(1); t<time; ++t){
			/*! \brief There is no update when the time is equal to 0
			*/
			std::vector<unsigned int> index_of_spikers(net.update(t));
			for(unsigned int i(0);i<index_of_spikers.size();++i){
			out << t*Neuron::h_ << '\t' << index_of_spikers[i] << '\n';	
			}
		}
							
	} 
	
	
}

