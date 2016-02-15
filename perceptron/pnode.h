#pragma once

#include <array>

/*
Implementation of averaged perceptron node
*/

class pnode {
	
	/// Node level for nn
	const int lvl;

	/// Number of features
	const int max;

	/// The weights for perceptron node
	long * weight;
	long bias;

	/// cached weights and biases
	long * cWeight;
	long cBias;


public:

	/// Constructor and destructor
	pnode(int lvl, int max);
	~pnode();

	/// Initialization mode
	void init(int mode);

	/// Getters and Setters
	const long getWeight(int i);
	void setWeight(int i, long val);

	const long getBias();
	void setBias(long val);

	const long getCWeight(int i);
	void setCWeight(int i, long val);

	const long getCBias();
	void setCBias(long val);

	/// Generate averaged weights and bias
	long * averagedWeight(int c);
	long averagedBias(int c);


};