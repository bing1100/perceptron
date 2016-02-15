#include "pnode.h"
#include <iostream>

// Constructor
pnode::pnode(int level, int max) :

	lvl(level),
	max(max)

{

	weight = new long[max];
	bias = 0;

	cWeight = new long[max];
	cBias = 0;

}

// destructor
pnode::~pnode() {

	delete[] weight;
	delete[] cWeight;

}

// TODO: Depending on mode change how the values are initialized
void pnode::init(int mode) {

	switch (mode) {

	case 0 :
		
		break;
	case 1 :
		
		break;
		//...

	}


}

/// Getters and Setters

// returns the long at idx i for weight
// input: int i - index value to check
// ouput: the value of array weight at i
const long pnode::getWeight(int i) {

	// Check bounds
	if (0 <= i  && i <= max) {

		return weight[i];

	}

	// The indx is invalid
	std::cerr << "Weight is out of bound" << std::endl;

	return 0;
}

// sets the weight at indx i to be val
// input: int i is the indx that we want to change
//        long val is the value we want to change to
// output: void
void pnode::setWeight(int i, long val) {

	// Check the bounds
	if (0 <= i  && i <= max) {

		weight[i] = val;

	}
	else {

		std::cerr << "Weight is out of bound" << std::endl;

	}

	

}

// returns bias
// input: NA
// ouput: the value of bias
const long pnode::getBias() {

	return bias;

}

// sets the bias to be val
// input: long val is the value we want to change to
// output: void
void pnode::setBias(long val) {

	bias = val;

}

// returns the long at idx i for cWeight
// input: int i - index value to check
// ouput: the value of array weight at i
const long pnode::getCWeight(int i) {

	// Check bounds
	if (0 <= i  && i <= max) {

		return cWeight[i];

	}

	// The indx is invalid
	std::cerr << "bias is out of bound" << std::endl;

	return 0;

}

// sets the cWeight at indx i to be val
// input: int i is the indx that we want to change
//        long val is the value we want to change to
// output: void
void pnode::setCWeight(int i, long val) {

	// Check the bounds
	if (0 <= i  && i <= max) {

		cWeight[i] = val;

	}
	else {

		std::cerr << "Weight is out of bound" << std::endl;

	}

}

// returns cBias
// input: NA
// ouput: the value cBias
const long pnode::getCBias() {

	return cBias;

}

// sets the cBias to be val
// input: long val is the value we want to change to
// output: void
void pnode::setCBias(long val) {

	cBias = val;

}

/// Generate averaged weights and bias

// Generates the average weight array and returns it
// input: NA
// output: the averaged weight array
long * pnode::averagedWeight(int c) {

	long * aWeight = new long[max];

	for (int i = 0; i < max; i++) {

		aWeight[i] = weight[i] - cWeight[i] / c;

	}

	return aWeight;
}

// Generates the average bias array and returns it
// input: NA
// output: the averaged bias array
long pnode::averagedBias(int c) {

	return bias - cBias / c;

}