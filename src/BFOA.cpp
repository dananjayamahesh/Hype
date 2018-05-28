#include <stdio.h>
#include "headers/BFOA.h"
#include "headers/OptFunctions.h"
#include "headers/Population.h"
/*
############################# BFOA ################################
Project : Bacterial Foraging Optimization Algorithm 
Author  : Mahesh Dananjaya
Date    : 2018/05/01
###################################################################
*/
BFOA::BFOA(OptFunctions *optfunc){
       id = 1;
       //optf = new OptFunctions();
       optf = optfunc;
       printf("%s\n","Constructor");
   }
BFOA::~BFOA(){
	id =0;
	printf("%s\n","Virtual Destructor");
}
int BFOA::getID(){
       return id;
}

int BFOA::setupParam
(
	int (OptFunctions::*optimizationFunction)(),
	int n = 100, 
	  //http://www.cplusplus.com/forum/beginner/6596/
	int lb = -20,
	int ub = 20,
	int dimension = 2,
	int iteration = 100,
	int Nre = 16,
	int Ned = 4,
	int Nc = 2,
	int Ns = 12,
	double C = 0.1,
	double Ped = 0.25,
	double Da = 0.1,
	double Wa = 0.2,
	double Hr = 0.1,
	double Wr = 10,
	int lamda = 400,
	double L = 0.03,
	std::string arga = "none",
	std::string argj = "none",
	bool arged = false,
	std::string search_type = "continuous",
	std::string search_strategy = "min"
)    
{
   return 0;
}

void BFOA::printParam(){
	printf("%s\n", "Paramters");
}

int BFOA::process(int n, int (OptFunctions::*optimizationFunction)()){
	//cout << parameter;
	(optf->*optimizationFunction)();
	return 0;
}

int BFOA::start(int n, int (BFOA::*optimizationFunction)()){
	//cout << parameter;
	(this->*optimizationFunction)();
	return 0;
}

int BFOA::revenueFunction(){
	printf("%s\n","Revenue Function");
	return 0;
}


