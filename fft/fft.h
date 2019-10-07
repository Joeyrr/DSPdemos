#include <complex>

#ifndef _DIF2_H_
	#define _DIF2_H_
	// in-place radix 2 decimation in time
	void dit2(std::complex<double>* InData, int length, int flag);
	// in-place radix 2 decimation in frequency
	void dif2(std::complex<double>* InData, int length, int flag);
#endif

