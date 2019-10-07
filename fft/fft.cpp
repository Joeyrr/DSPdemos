#include <iostream>
#include <complex>
#include "fft.h"
using namespace std;
typedef complex<double> cd;
extern const double pi = acos(-1);
extern const cd i(0, 1);

void dit2(cd* InData, int length, int flag);
void dif2(cd* InData, int length, int flag);
int reverseIndex(int ii, int L);
void bitReverse(cd* InData, int length);

// flag == 1 fft, flag == -1 ifft
void dit2(cd* InData, int length, int flag){
	bitReverse(InData, length);
	for(int ii = 1; (1<<ii) <= length; ii++){
		int n = 1<<ii;
		cd wn = exp(i*(double)flag*(-2.*pi)/(double)n);
		for(int j = 0; j < length; j+=n){
			for(int k = 0; k < n/2; k++){
				cd t = pow(wn, k) * InData[j + k + n/2];
				cd u = InData[j + k];
				InData[j + k] = u + t;
				InData[j + k + n/2] = u - t;
			}
		}
	}
	if(flag == -1){
		for(int ii = 0; ii < length; ii++){
			InData[ii] /= length;
		}
	}
}
void dif2(cd* InData, int length, int flag){
	int r=log(length)/log(2);
	cd tmp,wn;
	for(int ii=1;ii<=r;ii++){
		int step=1<<(r-ii+1);
		for(int j=0;j<length/step;j++){
			cd wn(1,0);
			for(int k=0;k<step/2;k++){
				cd tmp=InData[j*step+k];
				InData[j*step+k]=InData[j*step+k]+InData[j*step+step/2+k];
				InData[j*step+step/2+k]=(tmp-InData[j*step+step/2+k])*wn;
				wn=wn*exp(i*(double)flag*(-2.*pi)/(double)step);
//				cout << "ii=" << ii << " j=" << j << " k=" << k << " step=" << step << endl;
//				cout << "wn = " << wn << endl;
			}
		}
	}
	if(flag==-1){
		for(int ii=0;ii<length;ii++){
			InData[ii]/=length;
		}
	}
	bitReverse(InData, length);
}
int reverseIndex(int ii, int L){
	int index = 0;
	for(int j = 0; j < L; j++){
		if(1<<(L-j-1) & ii){
			index |= 1<<j;
		}
	}
	return index;
}
void bitReverse(cd* InData, int length){
	int L = log(length) / log(2);
	for(int ii = 0; ii < length; ii++){
		int l = reverseIndex(ii, L);
		if(ii < l){
			cd tmp = InData[ii];
			InData[ii] = InData[l];
			InData[l] = tmp;
		}
	}
}
