# cppcourse-brunel
The final stage of the neuron project

Instruction to compile my program -> object: Neuron
1) cmake .
2) make
3) ./Neuron

Instruction to test my program -> object: Unittest
1) cmake . (if not already done)
2) make test (if make not already done)
3) ./Unittest

Instruction to create the doxygen documentation
1)cmake . (if not already done)
2) make doc


The program is made of the following classes : a)Neuron, b)Network, c)Experiment.

a) The class Neuron takes care of every single neuron
- Update the membrane potential of the neuron when update is called

b) The class Network has a vector<Neuron> as an attribute
 - Creates the connexions between the neurons
 - Calls Neuron::update of every neuron of the network
 - Send the PPS to the connected neurons
 
 c) The class Experiment creates a network and then call Network::update at each step of time
 
 There is also a main program where you can set how many seconds the simulation will last.
 
 
