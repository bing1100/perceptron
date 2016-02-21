#include <iostream>
#include "averagePerceptron.h"

/// Constructor and destructor

// constructor
// input: numFeatures is the number of features that there are
// output: NA
averagedPerceptron::averagedPerceptron(int numFeatures) :
	
	wNode(new pnode(0, numFeatures)),
	c(0),
	numF(numFeatures)

{

}

// destructor
// input: NA
// output: NA
averagedPerceptron::~averagedPerceptron() {

	delete wNode;

}

// copy constructor
// input: averagePerceptron object to be copied
// output: NA
averagedPerceptron::averagedPerceptron(averagedPerceptron * perceptron) {

	// Deep copy over the wNode object
	wNode = new pnode(perceptron->wNode);

}

/// Training functions

// singleTrain trains wNode with the parameter array for the first numFeatures features
// input: long * arrlong is the array of features 
// ouput: NA
void averagedPerceptron::singleTrain(long * arrlong) {

	// Store the true value of the features
	int y = arrlong[0];

	// Running sum to calculate dot product of w*features
	int wx;

	// Calculate the dot product
	for (int i = 0; i < numF; i++) {

		wx += wNode->getWeight(i) * arrlong[i + 1];

	}

	// Check to see if the weights predicted incorrectly
	if ( y * ( wx + wNode->getBias()) <= 0) {

		// update the weights and cached weights respectivly
		for (int j = 0; j < numF; j++) {

			wNode->setWeight(j, wNode->getWeight(j) + y * arrlong[j + 1]);
			wNode->setCWeight(j, wNode->getCWeight(j) + c * y * arrlong[j + 1]);

		}

		// update the bias and cached bias respectively
		wNode->setBias(wNode->getBias() + y);
		wNode->setCBias(wNode->getCBias() + c * y);
	}

	// Increase the counter
	c++;
}

// arrayTrain trains the wNode with an array 
// input: the array of training data to train with
// output: NA
void averagedPerceptron::arrayTrain(long ** arrarrlong, int len) {

	// iterate over the length
	for (int i = 0; i < len; i++) {

		// Call the single train function on each idx in the array of idx
		singleTrain(arrarrlong[i]);

	}

}

// classify classifies the input features
// input: an array of features
// ouput: the classification of the point
long averagedPerceptron::classify(long * arrlong) {

	// Get the average weight and bias
	long * weights = wNode->averagedWeight(c);
	long bias = wNode->averagedBias(c);

	// Running sum to calculate dot product of w*featues
	int wx;

	// Calculate the dot product
	for (int i = 0; i < numF; i++) {

		wx += weights[i] * arrlong[i + 1];

	}

	// Return the value
	return wx + bias;

}

// precision calculates the precision metric ( number of correct k classifications / number of k classifications found by perceptron)
// input: an array of test points and a head and tail idx
// output: the value of the quotient
double averagedPerceptron::precision(long ** arrarrlong, int hIdx, int tIdx, bool pos) {

	// number of correct k classifications
	int i = 0;

	// number of k classifications
	int s = 0;

	// Iterate over the correct section of the array
	for (int i = hIdx; i < tIdx; i++) {

		// Set the correct classification
		long y = arrarrlong[i][0];

		// Set the classification the perceptron found
		long x = classify(arrarrlong[i]);

		// Check if it is the classification that we want to check
		if (x >= 0 || !pos) {

			s++;

			// check if the classification is correct
			if (x * y >= 0) {

				i++;

			}

		}

	}

	// return the quotient
	return i / s;

}

// recall calculates the recall metric ( number of correct k classifications / number of total k classifications)
// input: an array of test points and a head and tail idx
// output: the value of the quotient
double averagedPerceptron::recall(long ** arrarrlong, int hIdx, int tIdx, bool pos) {

	// number of correct k classifications
	int i = 0;

	// number of total k classifications
	int t = 0;

	// Iterate over the correct section of the array
	for (int i = hIdx; i < tIdx; i++) {

		// Set the correct classification
		long y = arrarrlong[i][0];

		// Set the classification the perceptron found
		long x = classify(arrarrlong[i]);

		// Check if it is the classification that we want to check
		if (y >= 0 || !pos) {

			t++;

			// check if the classification is correct
			if (x * y >= 0) {

				i++;

			}

		}

	}

	// return the quotient
	return i / t;

}