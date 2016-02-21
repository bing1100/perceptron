#pragma once

#include "pnode.h"

class averagedPerceptron {

	// The worker node
	pnode * wNode;

	// The number of times wNode has been trained
	int c;

	// the number of features there are
	int numF;

public:

	/// constructor and destructor
	averagedPerceptron(int numFeatures);
	~averagedPerceptron();
	averagedPerceptron(averagedPerceptron * perceptron);

	/// Training tools/modes
	void arrayTrain(long ** arrarrlong, int len);
	void singleTrain(long * arrlong);

	/// classify a point after training
	long classify(long * arrlong);

	/// Metrics of success for particular training
	double precision(long ** arrarrlong, int hIdx, int tIdx, bool pos);
	double recall(long ** arrarrlong, int hIdx, int tIdx, bool pos);

};