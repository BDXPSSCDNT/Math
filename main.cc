#include "c_math.h"
#include <iostream>

using namespace std;




int main(const int argc, const char *argv[]){

	if(argc < 2){
		cout << "Usage : ./out [sqrt args]" << endl;
		return -1;
	}

	double sqrt_arg = stod(*(argv + 1));

	cout << "sqrt("<<sqrt_arg << ") = " << f_sqrt(sqrt_arg) << endl;

	return 0;
}