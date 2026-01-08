#include "c_math.h"
#include <iostream>

using namespace std;


static double sqrtAccuracy = 10e-15;

static double f_abs(double value){
	return (value < 0.0) ? -1.0 * value : value;
}

/*--------------------------------------------------------*/

double f_sqrt(double value){

	if(value < 0.0){
		cerr <<"f_sqrt :: Domain error >> param [value = " << \
		value << "] is negative" << endl;
		return 0.0;
	}

	double root = (value < 1.0) ? 1.0 : value;
	double inf  = 0.0;
	double sup  = root;

	while(f_abs(root * root - value) > sqrtAccuracy){

		double avg = (inf + sup) / 2.0;

		if(avg * avg > value){
			sup = avg;
		}else{
			inf = avg;
		}

		root = (inf + sup) / 2.0;
		if(f_abs(root - avg) < sqrtAccuracy) return root;
	}
	return root;
}


/*--------------------------------------------------------*/

double fastPower(double x, unsigned int n){
	double result = 1;
	double power  = x; 
	while(n > 0){
		if(n % 2 == 1){
			result = result * power;
		}
		power = power * power;
		n = (n / 2);
	}
	return result;
}


/*--------------------------------------------------------*/

double nthRoot(double value, unsigned int n){
	if(n == 0){
		cerr <<"Error : n = 0" << endl;
		return 0.0;
	}

	if((value < 0.0) && !(n % 2)){
		cerr <<"Param[ n = "<< n << ", value = "<< value << \
		"] >> Domain error " << value << "< 0.0 and (" << \
		n <<" % 2) == 0" << endl;
		return 0.0;
	}

	int IsNegative = (value < 0.0) ? -1.0 : 1.0;

	double root = f_abs((value < 1.0) and (value > -1.0) ? 1.0 : value);
	double inf  = 0.0;
	double sup  = root;

	while(f_abs(IsNegative * value - fastPower(root,n)) > sqrtAccuracy){
		double avg = (inf + sup) / 2;
		if(fastPower(avg,n) > IsNegative * value){
			sup = avg;
		}else{
			inf = avg;
		}
		root = (inf + sup) / 2;
		if(f_abs(root - avg) < sqrtAccuracy) return IsNegative * root;
	}
	return IsNegative * root;
}