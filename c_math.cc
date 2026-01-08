#include "c_math.h"
#include <iostream>

using namespace std;

static double sqrtAccuracy = 10e-15;


static double f_abs(double value){
	return (value < 0.0) ? -1.0 * value : value;
}


double f_sqrt(double value){

	if(value < 0.0){
		cerr << "f_sqrt :: Domain error >> param [value = " << \
		value << "] is negative" << endl;
		return 0.0;
	}


	double root = (value < 1.0) ? value * 10.0 : value;
	double inf = 0.0;
	double sup = root;

	while(f_abs(root * root - value) > sqrtAccuracy){

		double avg = (inf + sup) / 2;

		if(avg * avg > value){
			sup = avg;
		}else{
			inf = avg;
		}

		root = (inf + sup) / 2;
		if(f_abs(root - avg) < sqrtAccuracy) return root;
	}
	return root;
}