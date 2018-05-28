#include <stdio.h>
#include "headers/OptFunctions.h"

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