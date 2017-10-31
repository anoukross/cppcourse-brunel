#include "Experiment.hpp"
#include <iostream>
#include <fstream>

void Experiment::launchSimulation(unsigned int steps_number){
	Network net;
	for(unsigned int t(1); t<steps_number; ++t){
			/*! \brief There is no update when the time is equal to 0
			*/
			net.update(t);
							
	} 
	
}

void Experiment::fetchData(unsigned int time_steps, unsigned int indice){
	if(time_steps%10==0){		
		std::ofstream out("spikes.txt", std::ios_base::app);
		if (out.fail()){
			std::cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat" << "en écriture." << std::endl;
		}else{
			out << time_steps*Neuron::h_  << '\t' << indice << '\n';
		}
	}
	
}

void Experiment::cleanData(){
	std::ofstream out("spikes.txt");
	if (out.fail()){
			std::cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat" << "en écriture." << std::endl;
		}else{
			out << "";
		}
	
}
