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
		const double capacity_=1; /**< capacity of the membrane = 1 pF=10⁻12 Farad  */
		const double tau_=20; /**< tau_ correspond to the membrane resistance * the Capacity (=resistance_*capacity_*C) in ms  */
		const double resistance_=tau_/capacity_; /**< resistance_ is the membrane resistance in GΩ*/
		const double tau_ref_=2; /**< tau_ref_ = tau refractory which lasts 2 ms */
		const double erest_=10; /**< erest_ = energy at rest which is 10mV */
		const double v_reset_=0; /**< v_reset_ = Membrane potential during the refractory period in mV */
		const double v_th_=20; /**<  v_th_ = Potential threshold; if a Neuron's potential is above -> there is a spike */
		const double h_=0.1; /**< h = step of time in 0.1 ms */
		const int step_=h_*10; /**< step_ -> one step of time corresponds to 0.1 ms, replace h, resolves the problem of floating point */
		const double c1_=exp(-(h_/tau_)); /** < c1_  = constant needed in the calculations of the membrane potential */
		const double c2_=resistance_*(1-c1_); /**< c2_ = constant needed in the calculations of the membrane potential */
		const unsigned int delay_=15; /**< delay of transmission(1.5ms) between the neurons that spikes and their targets */
		static constexpr unsigned int dmax_=16; /**< dmax_ = Maximal delay of transmission + 1, delay of 16 corresponds to 1.6ms */
		const double eta_=2; /** eta=v_ext_/v_th_ */
		const double nu_ext_=eta_*v_th_/(je_*tau_); /**< nu_ext_ is used to create the background noise of the cortex */


		/**
		*  attributes of the class Neuron
		*/
		double v_; /**< v_ = Membrane potential in mV */
		unsigned int index_; /**< index_ = number attributed to one particular neuron, is between 0 and [nb_neurons-1] (12499)*/
		unsigned int spikes_number_; /**< spikes_number_ = number of time a neuron has spiked */
		std::vector<unsigned int> spikes_time_; /** spikes_time_ registers the time associated with a particular spike ->spikes_time_[i] is the time at which the ith spike occurred */
		std::array<double, dmax_> incoming_spikes_; /** incoming_spikes_ = buffer of the size dmax_(delay maximal +1) where each step of time is associated with the amplitude of the postsynaptic weights arriving from the neurons targeting this one that have spiked */
		std::vector<unsigned int> outcoming_connexions_; /**< outcoming_connexion_ is a tab listing all the indices of the neurons that are a target of this one   */
		unsigned int clock_; /**< clock_ = internal clock of a neuron */

	public:

		/**
		 * Public Static constant because need to be accessed from outside (in Network), but not specific to a single neuron
		 * no getter because cannot have a static method that is const
		 */
		static constexpr double je_=0.1; /**< je_ = amplitude of the excitatory postsynaptic weight je_ = 0.1mV */
		static constexpr double g_=5; /**< g_ = g_=|ji_|/|je_| -> ji_ is g_(5) times stronger than je_, where ji_ is the amplitude of the inhibitory postsynaptic weight */

		/**
		*  Constructor
        * @param index the index of the neuron going from 0 to nb_neurons-1(12499)
        * @param v the membrane potential of the neuron in mV, by default initialisation of the membrane potential v_ at 0.0 mV
        */
		Neuron(unsigned int index, double v=0.0);

		/**
		 * Getters
		 */
		double getPotential() const; /**< @return v_ the membrane potential in mV*/
		unsigned int getIndex() const; /**< @return index_ the index of the neuron, between 0 and nb_neurons-1(12499)*/
		std::vector<unsigned int> getSpikesTime() const; /**< @return spikes_time_  the time of the spikes that have occurred */
		unsigned int getSpikesNumber() const; /**< @return spikes_number_  the number of time a neuron has spiked*/
		std::array<double, dmax_> getIncomingSpikes() const; /**< @return  incoming_spikes_ the buffer containing the incoming spikes, @see incoming_spikes_ */
		std::vector<unsigned int> getOutcomingConnexions() const; /**< @return  outcoming_connexions_ the outcoming connexion of a neuron */
		double getResistance() const; /**< @return resistance_  the membrane resistance */
		double getDelay() const; /**< @return delay_ the delay of transmission of the PPS weight between one neuron and his targets */
		unsigned int getClock() const; /**< @return  clock_ the internal clock of the neuron */

		/**
		 * Setters
		 */
		void setPotential(double v); /**< @param v membrane potential value that will replace the actual v_  */

		/** @param index index of a neuron that receive the connexion from this neuron
		 *this method will push_back the attribute outcoming_spikes_ with the value of the index
		 * when the connexions are created in the constructor of Network
		 * @see outcoming_spikes_
		 * @see Network::Network()
		 */
		void setOutcomingConnexions(unsigned int index);

		/**
		 * The method receiveSpikes is used whenever a neuron that has targets spikes,
		 * it adds in the compartment of the targeted neuron corresponding to (delay_+clock_)%dmax_ of the buffer incoming_spikes_ the value weight
		 * @see incoming_spikes_
		 * @param weight the amplitude of the postsynaptic current
		 * 0.1mV for the excitatory and 0.5 mV for the inhibitory
		 */
		void receiveSpikes(double weight);

		/**
		 * @return true if the neuron is in a refractory period
		 */
		bool isRefractory();

		/**
		 * update the neuron state from time t to time t+T, where T is n*h (h step of time)
		 * This method recalculates the membrane potential at each step of time, except if the neuron is in his refractory period
		 * The membrane potential is calculated by (c1_*v_+I*c2_+d(gen)) where d(gen) is a random value following a poisson distribution of (nu_ext_*h_)
		 * It then adds, the postsynaptic current if there is one associated with the step of time @see receiveSpikes(double weight)
		 * It verifies whether a neuron has spiked -> if it has, spikes_number_ is incremented and spikes_time_ record the current time
		 * The buffer incoming_spikes_ is reset to 0 if a neuron has spiked or if it is in its refractory period
		 * The personal time of the neuron is finally incremented
		 * @param I corresponds to the external current, always 0 in this simulation
		 * @param time corresponds to the simulation time
		 * @return true if the neuron has spiked
		 */
		bool update(double I, unsigned int time);



};

#endif
