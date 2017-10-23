#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <array>
#include <cmath>


class Neuron{
	private:
	
		//Constantes de classe
		const double tau=20; //tau = R*C , [ms]
		const double C=1; // capacity 1 pF=10⁻12 Farad
		const double R=tau/C; //Membrane resistance
		const double tau_ref=2; //tau refractory 2 ms
		const double Erepos=10; //10mV
		const double V_reset=0; // mV Membrane potential during the refractory time
		const double V_th=20; //Valeur du potentiel qui cause un spike (Potential threshold)
		const int step=1; //remplace le pas de temps h
		const double c1=exp(-(h/tau));
		const double c2=R*(1-c1);
		const unsigned int Dmax=16; //Maximal delay of transmission + 1 & delay of 16 means 1.6ms 
		

		//atrributs
		double V; //Membrane potential 
		unsigned int indice;
		unsigned int spikesNumber; //Number of spikes
		std::vector<double> spikesTime; // The times when the spikes occured
		unsigned int clock;
		std::vector<double> incoming_spikes; //Each step of time is associated with the amplitude of the spikes arriving from the neighbours at that time
		double J;
		
	public:
	
		//Constante de classe publique
		static constexpr double h=0.1; //pas de temps h = 0.1 ms
		static constexpr double V_ext=0.02; //V_ext= 2* V_th/(1000*0.1*20)
		static constexpr unsigned int Ce=1000; //Number of excitatory connexion
		static constexpr unsigned int Ci=250; //Number of inhibitory connexion
		
		
		//Constructeur et destructeur
		Neuron(double weight, double potential=0.0); //Initialisation par défaut à 0.0
		~Neuron();
		
		//Getters
		double getPotential() const;
		double getResistance() const;
		double getWeight() const;
		unsigned int getSpikesNumber() const;
		std::vector<double> getSpikesTime() const;
		
		//Setters
		void setPotential(double potential);
		void receive_spikes(unsigned int delay, double weight);
		
		//bool
		bool isRefractory();
		
		//Update
		bool update(double I, unsigned int time); //update the neuron state from time t to time t+T, where T is n*h (h pas de temps)	
								// I external current
								//Returns true if a neuron has spikes
	

};

#endif
