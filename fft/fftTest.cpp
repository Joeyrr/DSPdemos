#include <iostream>
#include <complex>
#include "fft.h"
using namespace std;
typedef complex<double> cd;
//const double pi = acos(-1);
//const cd i(0, 1);

int main(){
	cd x[16];
	for(int ii = 0; ii < 16; ii++){
		x[ii] = ii;
	}
//	bitReverse(x, 16);
	dit2(x, 16, 1);
	for(int ii = 0; ii < 16; ii++){
		cout << x[ii] << endl;
	}
}
