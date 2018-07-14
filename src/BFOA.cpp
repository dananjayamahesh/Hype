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
	//Create New Population
	printf("Creating a new population..........\n");
	this->pop = new Population (n,ub,lb,dimension);
	ic:
    this->id = id;  		//Process ID
	this->n = n;        //Number of Individuals: Population Size
	this->function = function;		//Fitness Function
	this->lb = lb;       //Lowerbound
	this->ub = ub;        //Upper Bound
	this->dimension = dimension;  //Dimenstion
	this->iteration = iteration;//Number of Iteration
	this->Nre = Nre;       //Number of Reproduction Stages
	this->Ned = Ned;        //Number of Elimination-Dispesal
	this->Nc = Nc;         //Number of Chemotaxix Stages
	this->Ns = Ns;        //Number of Swiming Stages
	this-> C = C;     //Step Sizes
	this-> Ped = Ped;  //Probability of Elimination-Dispersal
	this-> Da = Da;    //Depth of Attractants
	this-> Wa = Wa;    //Width of Attractants
	this-> Hr = Hr;    //Height of the Repellent
	this-> Wr = Wr;        //Width of the Repellent
	this-> lamda = lamda ;    //Lambda = 400
	this-> L = L;    //L paramater
	this-> arga = arga;
	this-> argj = argj;
	this-> arged = arged;
	this-> search_type = search_type;
	this-> search_strategy = search_strategy;

	//this->agents = new double[n][dimension];

	printf("New population has been created.\n");

   return 0;
}

void BFOA::printParam(){
	printf("%s\n", "Paramters");
}

int BFOA::process(int n, int (OptFunctions::*optimizationFunction)()){
	//cout << parameter;
	(optf->*optimizationFunction)();

	//Initializing 2D vector
    //this->agents
    double agents [n][dimension];
    double j_obj[n];
    double j_last[n];
    double j_best;

    int step_size = 1;


    for ( int i = 0; i < this->n; i++ ) {
    	for (int j= 0; j< this->dimension; j++){
    		 agents[i][j] = rand() % (this->ub - this->lb) + this->lb;
    	}     
    }

   
    for (int i = 0; i < this->n; ++i)
    {
        for (int j = 0; j < this->dimension; ++j)
        {
           // std::cout << agents[i][j] << ' ';
        }
        //std::cout << std::endl;
        j_obj[i] = optf->functionGaussian(agents[i]);
    }

    //Elimination and Dispersal Step
   	for (int l=0; l< this->Ned; l++){
   		//Reproduction Step
   		for(int k=0; k< this->Nre; k++){
   			//Chemotaxis Staeps
   			for(int j=0; j< this->Nc; j++){
   				//Agents
   				for(int i=0;i< this->n; i++){
   					//Every Agent Performs
   					j_last[i] = j_obj[i];

   					//Chemotaxix Step
   					for (int d = 0; d < this->dimension; d++){
   						double c_d = rand() % (2*step_size) - step_size;
   						agents[i][d] += c_d;
   					}

   					j_obj[i] = optf->functionGaussian(agents[i]);
   					
   					//printf("Fitness Value %f\n", j_obj[i]);

   					for(int m =0; m<this->Ns;m++){
   						//Every Swarming Step
   						if(j_obj[i]>j_last[i]){

   							j_last[i] = j_obj[i];
   					
   							for (int d = 0; d <this->dimension; d++){
   								double c_d = rand() % (2*step_size) - step_size;
   								agents[i][d] += c_d;
   							}
		
   							j_obj[i] = optf->functionGaussian(agents[i]);

   						}else{
   							break;
   						}

   					}
   				}

   				//Best solutions
   				double j_best_pop = 0 ;
   				int j_best_index = 0;

   				for(int i=0;i<this->n; i++){
                   //Find the Best Solution
   					if(j_obj[i] > j_best_pop){
   						j_best_pop = j_obj[i];
   						j_best_index = i;
   					}

   				}
   				printf("Best Index%d \n",j_best_index);
   				this->print_agent(agents[j_best_index]);
   			}
   		}
   	}


	return 0;
}

int BFOA::print_agent(double *agent){

	for (int j = 0; j < this->dimension; ++j)
        {
           std::cout << agent[j] << ' ';
        }
        std::cout << std::endl;

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

int BFOA::findOpt(){
	printf("%s\n","Optimization Procedure");
	printf("%s %d\n","Global Paramters", this->n);

	
	return 0;
}



