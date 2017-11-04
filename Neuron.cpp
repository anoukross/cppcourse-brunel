#include "Network.hpp"
#include <cassert>
#include <random>

/**
*  Constructor
*/
Neuron::Neuron(unsigned int index, double v)
: v_(v), index_(index), spikes_number_(0), clock_(0)
{
	/*! \brief At the beggining of the simulation, the neurons have not yet received a postsynaptic current
	 * ->Every compartment of incoming_spikes_ should equal 0.0
	 */
	for(unsigned int i(0);i<dmax_;++i){
		incoming_spikes_[i]=0.0;
	}
	
	/*! \brief To be sure that when we create a neuron, it has got not spike time
	 */
	spikes_time_.clear();
	outcoming_connexion_.clear();
}
		
/**
*  Getters
*/
double Neuron::getPotential() const{
	return v_;
}
double Neuron::getResistance() const{
	return resistance_;
}


double Neuron::getDelay() const{
	return delay_;
}


unsigned int Neuron::getIndex() const{
	return index_;
}

unsigned int Neuron::getSpikesNumber() const{
	return spikes_number_;
}
std::vector<unsigned int> Neuron::getSpikesTime() const{
	return spikes_time_;
}

std::array<double, Neuron::dmax_> Neuron::getIncomingSpikes() const{
	return incoming_spikes_;
}

unsigned int Neuron::getClock() const{
	
	return clock_;
}

std::vector<unsigned int> Neuron::getOutcomingConnexion() const{
	return outcoming_connexion_;
}

/**
*  Setter
*/
void Neuron::setPotential(double v){
	v_=v;
}

void Neuron::setOutcomingConnexion(unsigned int index){
	outcoming_connexion_.push_back(index);
}

//Receive spikes
void Neuron::receiveSpikes(double weight){
	unsigned int t_spike = (delay_+clock_)%dmax_;
	assert(t_spike < incoming_spikes_.size());
	/*! \brief the amplitude of the postsynaptic current is added in the buffer's compartment corresponding to (D_+clock_)%Dmax_ 
	*/
	incoming_spikes_[t_spike]+=weight; 
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
		
		/*! \brief The random generator follows a poisson distribution with λ = nu_ext_*h_, , static so that it is really random
		 */
		static std::poisson_distribution<> d(nu_ext_*h_);
		
		/*! \brief The external current I is equal to 0
		 */
		double v_new(c1_*v_+I*c2_+d(gen)); 
		
		/*! \brief If a spike is associated with the current time, we add it to the new potential
		 */
	
			v_new+=incoming_spikes_[clock_%dmax_];
			
			/*! \brief Reinitialisation of the value of my buffer corresponding to the compartment [clock%Dmax] that have just been used
			*/
		
		
		/*! \brief A spike occurres if the membrane potential is greater than the membrane potential threshold
		*/
		if(v_new > v_th_){
			spikes_time_.push_back(clock_); 
			spikes_number_+=1;
			
			/*! \brief After  a spike, the potential gets back to its reset value
			*/ 	
			hasSpiked=true;	
			}
		
		/*! \brief Modifies the attribute membrane potential V_
			*/
		v_=v_new;
	}else{
		v_=v_reset_;
	}
	
	/*! \brief The local clock of my neuron is incremented at the end of the update
	*/
	++clock_; 
	incoming_spikes_[clock_%dmax_]=0.0; 
	
		
	return hasSpiked;
}
