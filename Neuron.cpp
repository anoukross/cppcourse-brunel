#include "Network.hpp"
#include <cassert>
#include <random>

//Constructeur
Neuron::Neuron(unsigned int index, double J, double V)
: J_(J), V_(V), index_(index), spikes_number_(0), clock_(0)
{
	for(unsigned int i(0);i<Dmax_;++i){
		incoming_spikes_[i]=0.0;
	}
	
	spikes_time_.clear(); //To be sure that when we create a neuron it has got no spikes time 
}
		
//Getters
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

//Setters
void Neuron::setPotential(double V){
	V_=V;
}

//Receive spikes
void Neuron::receive_spikes(double J){
	unsigned int t_spike = (D_+clock_)%Dmax_;
	assert(t_spike < incoming_spikes_.size());
	incoming_spikes_[t_spike]+=J; //We add the weight of the postsynaptic current in the buffer compartment corresponding to (delay+clock)%Dmax
}

//bool
bool Neuron::isRefractory(){
	if(spikes_number_>=1){ //If it has already spiked
		if((clock_-spikes_time_[spikes_number_-1]) <= (tau_ref_/h_)){ //if the current time - the last spike time is smaller than the refractory period
			return true;
		}
	}
	return false;
}

		
//Update
bool Neuron::update(double I, unsigned int time){
	bool hasSpiked(false);
	if(!isRefractory()){ //If neuron is refractory -> neuron has spiked -> V is not modified
		std::random_device rd;
		std::mt19937 gen(rd());
		std::poisson_distribution<> d(V_ext_*J_*h_ *Ce_);
		double V_new(c1_*V_+I*c2_+d(gen)); //I= external current is equal to 0
		if(incoming_spikes_[clock_%Dmax_]>0.0){ //If a spike is associated with the current time, we add it to the new potential
			V_new+=incoming_spikes_[clock_%Dmax_];
			//std::cout << "Neuron " << indice+1 << " has received a spike at time " << time*h << " ms." <<std::endl;	//cannot spike at t=0
			incoming_spikes_[clock_%Dmax_]=0.0; //Reinitialisation of the value of my buffer corresponding to [clock%Dmax[ that have just been used
		}
		
		if(V_new > V_th_){
			spikes_time_.push_back(clock_); 
			spikes_number_+=1;
			V_new=V_reset_; //After  a spike, the potential gets back to its reset value	
			hasSpiked=true;	
			//std::cout << "Neuron " << indice+1 << " has spiked at time: " << time*h << " ms." << std::endl;
			}
		
		V_=V_new; //modify neuron potential
	}
	
	++clock_; 
	
		
	return hasSpiked;
}
