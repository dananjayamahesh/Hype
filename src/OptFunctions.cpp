#include <stdio.h>
#include "headers/OptFunctions.h"
#include <math.h>

OptFunctions::OptFunctions(int M, int R, int lrm, int T, int * Nr){

	this->M = M;
	this->R = R;
	this->lrm = lrm;
	this->T = T;
	this->Nr = Nr;
	printf("Revenue Optimization Paramters %d %d %d %d \n",M,R,lrm,T);
	//M =3, R_=2, lrm_=3, T_=2

}

OptFunctions::~OptFunctions(){
	
}

int OptFunctions::revenueFunction(){
	printf("%s\n","Revenue FUnction");

}

double OptFunctions::functionGaussian(double *x){
     //printf("%s\n", "Optimization Function 1");
    //return 10 - ((exp(-4 * log(2) * ((x[0] - 10)**2 + (x[1] - 10)**2) / 6**2)))
    return 10 - ((exp(-4 * log(2) * (pow((x[0] - 10),2) + pow((x[1] - 10),2)) / 6*6)));

	//return 0;

}