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
		const double C_=1; /**< C_ = capacity 1 pF=10⁻12 Farad  */
		const double tau_=20; /**< tau_ correspond to the membrance resistance * the Capacity (=R*C) in ms  */
		const double R_=tau_/C_; /**< R_ = Membrane resistance in GΩ*/  
		const double tau_ref_=2; /**< tau_ref_ = tau refractory which lasts 2 ms */
		const double Erest_=10; /**< Erest_ = energy at rest which is 10mV */
		const double V_reset_=0; /**< V_reset_ = Membrane potential during the refractory period in mV */
		const double V_th_=20; /**<  V_th_ = Potential threshold Value of the potential which causes a spike */
		const int step_=h_*10; /**< step_ -> one step of time corresponds to 0.1 ms, replace h, resolves the problem of the floating point */
		const double c1_=exp(-(h_/tau_)); /** < c1_  = constant need in the calcul of the membrane potential */
		const double c2_=R_*(1-c1_); /**< c2_ = constant need in the calcul of the membrane potential */
		const unsigned int D_=15; /**< D_ = delay of transmission(1.5ms) between the neurons that spike and their targets */
		static constexpr unsigned int Dmax_=16; /**< Dmax_ = Maximal delay of transmission + 1, delay of 16 corresponds to 1.6ms */
		const unsigned int eta_=2; /** eta=V_ext_/V_th_ */
		const double nu_ext_=eta_*V_th_/(je_*tau_); /**< V_ext_= 2* V_th_/(1000*0.1*20)  */
		
		/**
		*  attributs of the class Neuron
		*/
		double V_; /**< V_ = Membrane potential in mV */
		unsigned int index_; /**< index_ = number attributed to one particular neuron, is between 0 and nb_neurons-1(12500-1)*/
		unsigned int spikes_number_; /**< spikesNumber_ = number of time a neuron has spiked */
		std::vector<double> spikes_time_; /** spikesTime_ registers the moment when the spikes of a neuron occured */
		unsigned int clock_; /**< clock = internal clock of a neuron */
		std::array<double, Dmax_> incoming_spikes_; /** incoming_spikes_ = buffer of the size Dmax(delay maximal +1) where each step of time is associated with the amplitude of the spikes arriving from the other neurons targeting this one  at that time */
		
	public:
	
		/**
		*  public static attributs of the class Neuron
		* Do not change from one neurons to another and need to be accessed from outside the class -> no getter because static method should not be constant
		*/
		static constexpr double h_=0.1; /**< h = step of time in 0.1 ms */
		static constexpr double je_=0.1; /**< J_ = amplitude of the postsynaptic current J_ = 0.1mV for the excitatory */
		static constexpr double g_=5;
		
		
		/**
		*  Constructor
        * @param index  the index of the neuron going from 0 to nb_neurons-1(12500-1)
        * @param J the amplitude of the postsynaptic current 0.1 mV for the excitatory neurons, 0.5 for the inhibitory, by default the neuron is excitatory so J=0.1
        * @param V the membrane potential of the neuron in mV, bydefault initialisation of the membrane potential V_ at 0.0 mV
        */
		Neuron(unsigned int index, double V=0.0); 
		
		/** 
		 * Getters
		 */
		double getPotential() const; /**< @return V_ the membrane potential in mV*/
		double getResistance() const; /**< @return R_  the membrane resistance */
		double getDelay() const; /**< @return D_ the delay of transmission between one neuron and his targets */
		unsigned int getIndex() const; /**< @return index_ the index of the neuron, between 0 and nb_neurons-1(12500-1)*/
		unsigned int getSpikesNumber() const; /**< @return spikes_number_  the number of time a neuron has spikes*/
		std::vector<double> getSpikesTime() const; /**< @return spikes_time_  the time of the spikes that have occurred */
		
		/** 
		 * Setter 
		 */
		void setPotential(double V); /**<  set the membrane potential V_ to a given value V */
		
		/** 
		 * The method receive_spikes is used whenever a neuron that has targets spikes, 
		 * it adds in the compartment corresponding to (delay_+clock_)%Dmax_ of the buffer incoming_spikes_  the value of J
		 * @param J the amplitude of the postsynaptic current
		 * 0.1mV for the excitatory and 0.5 mV for the inhibitory
		 */
		void receive_spikes(double J); 
		
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
