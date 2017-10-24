#include "Neuron.hpp"
#include "Network.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
	
	Network net;
	
	double I(0); // External current (I=[0,400 pA])
	
	double startTime(0.0);
	double stopTime(0.0);
	

	cout << "Choose the stop time: ";
	cin >> stopTime;
	cout << endl;
	
	
	ofstream out("simulator.txt");
	unsigned int steps_number(stopTime/Neuron::h); //Division by h to get an integer
	
		for(unsigned int t(startTime/Neuron::h); t<steps_number; ++t){
			if (out.fail()){
				cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat"
				<< "en écriture." << endl;
			} else if (t>0) { //There is no update when the time is equal to 0
				for(unsigned int i(0); i<net.getNetwork().size(); ++i){
					for(unsigned int j(0); j<net.getNetwork().size(); ++j){
						if(i!=j){
							double weight(net.getCurrentWeights()[i][j]);
							net.connect(i,j, weight, I, t);
						}
						
					}
				
					out << "A temps: " << t*Neuron::h << " ms, le potentiel de membrane du neurone " << i+1 <<  " est: " << net.getNetwork()[i]->getPotential() << "." << endl;
				}
			}
		}
	
	
	return 0;
	
}
