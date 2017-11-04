#include "Experiment.hpp"
#include <iostream>
#include <fstream>
#include <vector>

void Experiment::launchSimulation(unsigned int time){
	time*=10; /**< to have step of time that corresponds to 0.1 ms and not 1ms */
	std::ofstream out("spikes.txt");
	Network net;
	if (out.fail()){
		std::cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat" << "en écriture." << std::endl;
	}else{
		for(unsigned int t(1); t<time; ++t){ /**< There is no update when the time is equal to 0 */
			std::vector<unsigned int> index_of_spikers(net.update(t)); /**< calls Network::update with this step of time and collect the indices of the neurons that spikes at this time */
			for(unsigned int i(0);i<index_of_spikers.size();++i){
				out << t << '\t' << index_of_spikers[i] << '\n';	
			}
		}
							
	} 
	
	
}

