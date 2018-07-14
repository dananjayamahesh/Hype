#ifndef HEADER_BFOA_H
#define HEADER_BFOA_H
#include <string>
#include "OptFunctions.h"
#include "Population.h"

class BFOA{   

    public:
    	int id ;  		//Process ID
		int n ;        //Number of Individuals: Population Size
		int function;		//Fitness Function
		int lb ;       //Lowerbound
		int ub ;        //Upper Bound
		int dimension;  //Dimenstion
		int iteration;//Number of Iteration
		int Nre;       //Number of Reproduction Stages
		int Ned;        //Number of Elimination-Dispesal
		int Nc;         //Number of Chemotaxix Stages
		int Ns;        //Number of Swiming Stages
		double C;     //Step Sizes
		double Ped;  //Probability of Elimination-Dispersal
		double Da;    //Depth of Attractants
		double Wa;    //Width of Attractants
		double Hr;    //Height of the Repellent
		double Wr;        //Width of the Repellent
		int lamda;    //Lambda = 400
		double L;    //L paramater
		std::string arga;
		std::string argj;
		bool arged;
		std::string search_type;
		std::string search_strategy;
    	OptFunctions *optf;
    	Population *pop; //Population Information earlier *

    	std::vector <double> opt_soultion;
    	double p_best;
    	double g_best;
    	double j_best;

    	//double agents[][];

    	//Process Control Variables
    	//double [] 
        
	  	BFOA(OptFunctions *optfunc);
		~BFOA();
		int getID();
		int setupParam (int (OptFunctions::*optimizationFunction)(),int n,  int lb , int ub , int dimension , int iteration,  int Nre, int Ned , int Nc , int Ns , double C , double Ped , double Da , double Wa , double Hr , double Wr , int lamda , double L , std::string arga , std::string argj , bool arged, std::string search_type , std::string search_strategy);
        void printParam();
		int process(int n, int (OptFunctions::*optimizationFunction)());
		int start(int n, int (BFOA::*optimizationFunction)());
		int revenueFunction();
		int findOpt();
		int print_agent(double *agent);

};

#endif /* HEADER_BFOA_H */