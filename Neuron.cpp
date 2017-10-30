#include "Network.hpp"
#include <cassert>
#include <random>
#include <iostream>

/**
*  Constructor
*/
Neuron::Neuron(unsigned int index, double J, double V)
: J_(J), V_(V), index_(index), spikes_number_(0), clock_(0)
{
	/*! \brief At the beggining of the simulation, the neurons have not yet received a postsynaptic current
	 * ->Every compartment of incoming_spikes_ should equal 0.0
	 */
	for(unsigned int i(0);i<Dmax_;++i){
		incoming_spikes_[i]=0.0;
	}
	
	/*! \brief To be sure that when we create a neuron, it has got not spike time
	 */
	spikes_time_.clear(); 
}
		
/**
*  Getters
*/
double Neuron::getPotential() const{
	return V_;
}
double Neuron::getResistance() const{
	return R_;
}

double Neuron::getWeight() const{
	return J_;
}

double Neuron::getDelay() const{
	return D_;
}


unsigned int Neuron::getIndex() const{
	return index_;
}

unsigned int Neuron::getSpikesNumber() const{
	return spikes_number_;
}
std::vector<double> Neuron::getSpikesTime() const{
	return spikes_time_;
}

/**
*  Setter
*/
void Neuron::setPotential(double V){
	V_=V;
}

//Receive spikes
void Neuron::receive_spikes(double J){
	unsigned int t_spike = (D_+clock_)%Dmax_;
	assert(t_spike < incoming_spikes_.size());
	/*! \brief the amplitude of the postsynaptic current is added in the buffer's compartment corresponding to (D_+clock_)%Dmax_ 
	*/
	incoming_spikes_[t_spike]+=J; 
}

//bool
bool Neuron::isRefractory(){
	/*! \brief check if it has already spiked, otherwise it cannot be in the refractory period
	*/
	if(spikes_number_>=1){ 
		/*! \brief check if the current time - the last spike time is smaller than the refractory period
		*/
		if((clock_-spikes_time_[spikes_number_-1]) <= (tau_ref_/h_)){ 
			return true;
		}
	}
	return false;
}

		
/**
*  Update
*/
bool Neuron::update(double I, unsigned int time){
	bool hasSpiked(false);
	/*! \brief If neuron is refractory -> neuron has spiked -> V will not be modified(insensitive to stimulation)
	 */
	if(!isRefractory()){ 
		/*! \brief Creation of a random device, static so that it is really random
		*/
		static std::random_device rd;
		static std::mt19937 gen(rd());
		
		/*! \brief The random generator follows a poisson distribution with λ = V_ext_*h_, , static so that it is really random
		 */
		static std::poisson_distribution<> d(V_ext_*h_);
		
		/*! \brief The external current I is equal to 0
		 */
		double V_new(c1_*V_+I*c2_+d(gen)); 
		
		/*! \brief If a spike is associated with the current time, we add it to the new potential
		 */
		if(incoming_spikes_[clock_%Dmax_]>0.0){
			V_new+=incoming_spikes_[clock_%Dmax_];
			//std::cout << "Neuron " << index_ << " has received a spike at time " << time*h_ << " ms." <<std::endl;	//cannot spike at t=0
			
			/*! \brief Reinitialisation of the value of my buffer corresponding to the compartment [clock%Dmax] that have just been used
			*/
			incoming_spikes_[clock_%Dmax_]=0.0; 
		}
		
		
		/*! \brief A spike occurres if the membrane potential is greater than the membrane potential threshold
		*/
		if(V_new > V_th_){
			spikes_time_.push_back(clock_); 
			spikes_number_+=1;
			
			/*! \brief After  a spike, the potential gets back to its reset value
			*/
			V_new=V_reset_; 	
			hasSpiked=true;	
			//std::cout << "Neuron " << index_ << " has spiked at time: " << time*h_ << " ms." << std::endl;
			}
		
		/*! \brief Modifies the attribute membrane potential V_
			*/
		V_=V_new;
	}
	
	/*! \brief The local clock of my neuron is incremented at the end of the update
	*/
	++clock_; 
	
		
	return hasSpiked;
}
