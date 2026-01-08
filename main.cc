#include "c_math.h"
#include <iostream>

using namespace std;




int main(const int argc, const char *argv[]){

	if(argc < 3){
		cout << "Usage : ./out [nthRoot arg1] [nthRoot arg2]" << endl;
		return -1;
	}

	double nthRoot_arg1 = stod(*(argv + 1));
	unsigned int n = atoi(*(argv + 2));


	cout << "nthRoot("<<nthRoot_arg1<<"," <<n<<") = " \
	<< nthRoot(nthRoot_arg1,n) << endl;

	return 0;
}