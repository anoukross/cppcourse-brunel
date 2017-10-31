#include "Network.hpp"
#include "googletest/include/gtest/gtest.h"
#include <vector>
#include <array>
#include <iostream>



TEST (NetworkTest, TargetsNumber){
	Network n;
	unsigned int nb_connexions(Network::Cei_);
	for(unsigned int t(0); t<Network::nb_neurons_;  ++t){ 
		
		EXPECT_EQ(n.getTargets(t).size(), nb_connexions);
	}
}

TEST (NetworkTest, weights){
	Network n;
	double weight(Neuron::je_);
	for(unsigned int t(0); t<Network::nb_excit_;  ++t){ 
		EXPECT_EQ(n.getWeight(t),weight);
	}
	for(unsigned int t(Network::nb_excit_); t<Network::nb_neurons_;  ++t){ 
		EXPECT_EQ(n.getWeight(t),(-weight*Neuron::g_));
	}		
	
}

TEST (NeuronTest, ConstructorGetters){
	Neuron n1(1, 5.5); //Initialisation d'un neurone d'indice 1 et de membrane potential 5.5
	EXPECT_EQ(n1.getPotential(), 5.5);
	EXPECT_EQ(n1.getIndex(), 1);
	EXPECT_EQ(n1.getSpikesNumber(), 0);
	EXPECT_EQ(n1.getClock(), 0);
	
	std::vector<unsigned int> spikesTime(n1.getSpikesTime());
	for(unsigned int i(0);i<n1.getSpikesTime().size();++i){
		EXPECT_EQ(spikesTime[i],0);
		EXPECT_EQ(n1.getIncomingSpikes()[i],0);
	}
	
	Neuron n2(2);
	EXPECT_EQ(n2.getPotential(), 0.0);
	EXPECT_EQ(n2.getIndex(), 2);
	
	
}

TEST (NeuronTest, Spike){
	Neuron n1(1); //Initialisation du potentiel de membrane à 0
	EXPECT_EQ(n1.isRefractory(),false);
	n1.setPotential(25.4);
	EXPECT_EQ(n1.getPotential(), 25.4);
	EXPECT_EQ(n1.update(0,1),true);
	EXPECT_EQ(n1.getPotential(),0.0);
	EXPECT_EQ(n1.getSpikesNumber(),1);
	EXPECT_EQ(n1.isRefractory(),true);	
}

TEST (NeuronTest, Recieve){
	Neuron n1(1);
	Neuron n2(2);
	EXPECT_EQ(n2.getIncomingSpikes()[0],0);
	n1.setPotential(21);
	double weight(Neuron::je_);
	n2.receive_spikes(weight);
	EXPECT_EQ(n2.getIncomingSpikes()[15],weight); //15 derniere case du buffer car t=1 15%1=15
	
}








	
	


