#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <array>
#include <cmath>


/**
 *  The Neuron class
 */

class Neuron{
	private:
	
		/**
		*  Constants specific to the Neuron
		*/
		const double capacity_=1; /**< capacity of the mebrane = 1 pF=10⁻12 Farad  */
		const double tau_=20; /**< tau_ correspond to the membrance resistance * the Capacity (=resistance_*capacity_*C) in ms  */
		const double resistance_=tau_/capacity_; /**< resistance_ is the membrane resistance in GΩ*/  
		const double tau_ref_=2; /**< tau_ref_ = tau refractory which lasts 2 ms */
		const double erest_=10; /**< erest_ = energy at rest which is 10mV */
		const double v_reset_=0; /**< v_reset_ = Membrane potential during the refractory period in mV */
		const double v_th_=20; /**<  v_th_ = Potential threshold; if a Neuron's potential is above -> there is a spike */
		const int step_=h_*10; /**< step_ -> one step of time corresponds to 0.1 ms, replace h, resolves the problem of floating point */
		const double c1_=exp(-(h_/tau_)); /** < c1_  = constant needed in the calcul of the membrane potential */
		const double c2_=resistance_*(1-c1_); /**< c2_ = constant needed in the calcul of the membrane potential */
		const unsigned int delay_=15; /**< delay of transmission(1.5ms) between the neurons that spike and their targets */
		static constexpr unsigned int dmax_=16; /**< dmax_ = Maximal delay of transmission + 1, delay of 16 corresponds to 1.6ms */
		const unsigned int eta_=2; /** eta=v_ext_/v_th_ */
		const double nu_ext_=eta_*v_th_/(je_*tau_); /**< nu_ext_ is used to create the background noise of the cortex */
		const double h_=0.1; /**< h = step of time in 0.1 ms */
		
		/**
		*  attributs of the class Neuron
		*/
		double v_; /**< v_ = Membrane potential in mV */
		unsigned int index_; /**< index_ = number attributed to one particular neuron, is between 0 and [nb_neurons-1] (12499)*/
		unsigned int spikes_number_; /**< spikes_number_ = number of time a neuron has spiked */
		std::vector<unsigned int> spikes_time_; /** spikes_time_ registers the time associated with a particular spike ->spikes_time_[i] is the time at which the ith spike occured */
		unsigned int clock_; /**< clock_ = internal clock of a neuron */
		std::array<double, dmax_> incoming_spikes_; /** incoming_spikes_ = buffer of the size dmax_(delay maximal +1) where each step of time is associated with the amplitude of the postsynaptic weights arriving from the neurons targeting this one that have spiked */
		std::vector<unsigned int> outcoming_connexion_; /**< outcoming_connexion_ is a tab listing all the indices of the neurons that are a target of this one   */
		
	public:
	
		/**
		*  public static attributs of the class Neuron
		* Do not change from one neurons to another and need to be accessed from outside the class -> no getter because static method should not be constant
		*/
		static constexpr double je_=0.1; /**< je_ = amplitude of the excitatory postsynaptic weight je_ = 0.1mV */
		static constexpr double g_=5; /**< g_ = g_=ji_/je_ -> ji_ is g_(5) times stronger than je_, where ji_ is the amplitude of the inhibitory postsynapic weight */
	
		
		
		/**
		*  Constructor
        * @param index  the index of the neuron going from 0 to nb_neurons-1(12499)
        * @param v the membrane potential of the neuron in mV, by default initialisation of the membrane potential v_ at 0.0 mV
        */
		Neuron(unsigned int index, double v=0.0); 
		
		/** 
		 * Getters
		 */
		double getPotential() const; /**< @return V_ the membrane potential in mV*/
		double getResistance() const; /**< @return R_  the membrane resistance */
		double getDelay() const; /**< @return D_ the delay of transmission between one neuron and his targets */
		unsigned int getIndex() const; /**< @return index_ the index of the neuron, between 0 and nb_neurons-1(12500-1)*/
		unsigned int getSpikesNumber() const; /**< @return spikes_number_  the number of time a neuron has spikes*/
		std::vector<unsigned int> getSpikesTime() const; /**< @return spikes_time_  the time of the spikes that have occurred */
		unsigned int getClock() const;
		std::array<double, dmax_> getIncomingSpikes() const;
		std::vector<unsigned int> getOutcomingConnexion() const;
		
		/** 
		 * Setter 
		 */
		void setPotential(double v); /**<  set the membrane potential V_ to a given value V */
		void setOutcomingConnexion(unsigned int index);
		/** 
		 * The method receive_spikes is used whenever a neuron that has targets spikes, 
		 * it adds in the compartment corresponding to (delay_+clock_)%Dmax_ of the buffer incoming_spikes_  the value of J
		 * @param J the amplitude of the postsynaptic current
		 * 0.1mV for the excitatory and 0.5 mV for the inhibitory
		 */
		void receive_spikes(double weight); 
		
		/** 
		 * @return true if the neuron is in a refractory period
		 */
		bool isRefractory();
		
		/** 
		 * update the neuron state from time t to time t+T, where T is n*h (h pas de temps)
		 * This method recalculates the mebrane potential at each step of time, except if the neuron is in his refractory period
		 * The membrane potential is calculated by (c1_*V_+I*c2_+d(gen)) where d(gen) is a random value following a poisson distibution of (V_ext_*J_*h_ *Ce_)
		 * It then adds, the postsynaptic current if there is one associated with the step of time @see receive_spikes(double J)
		 * It verifies whether a neuron has spiked -> if it has, spikes_number_ is incremented and spikes_time_ record the current time
		 * The personnal time of the neuron is finally incremented 	
		 * @param I corresponds to the external current
		 * @param time corresponds to the simulation time
		 * @return true if the neuron has spiked
		 */
		bool update(double I, unsigned int time); 
							
	

};

#endif
