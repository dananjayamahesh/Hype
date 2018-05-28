#include <stdio.h>
#include "headers/BFOA.h"
#include "headers/OptFunctions.h"

int main(){
 printf("%s\n","Hello");
 //BFOA bfoa;
 //int tmp = bfoa.getID();
 int M = 3;
 int R = 2;
 int lrm = 3;
 int T = 2;
 int *Nr ;

int id =0;  		//Process ID
int n = 100;        //Number of Individuals: Population Size
int function;		//Fitness Function
int lb = -20;       //Lowerbound
int ub = 20;        //Upper Bound
int dimension = 2;  //Dimenstion
int iteration = 100;//Number of Iteration
int Nre = 16;       //Number of Reproduction Stages
int Ned = 4;        //Number of Elimination-Dispesal
int Nc = 2;         //Number of Chemotaxix Stages
int Ns = 12;        //Number of Swiming Stages
double C = 0.1;     //Step Sizes
double Ped = 0.25;  //Probability of Elimination-Dispersal
double Da = 0.1;    //Depth of Attractants
double Wa = 0.2;    //Width of Attractants
double Hr = 0.1;    //Height of the Repellent
double Wr = 10;        //Width of the Repellent
int lamda = 400;    //Lambda = 400
double L = 0.03;    //L paramater
std::string arga = "none";
std::string argj = "none";
bool arged = false;
std::string search_type = "continuous";
std::string search_strategy = "min";
//OptFunctions *optf;
//bfoa->setupParam(&OptFunctions::revenueFunction,n,lb,ub,dimension,iteration,Nre,Ned,Nc,Ns,C,Ped,Da,Wa,Hr,Wr,lamda,L,arga,argj,arged, search_type,search_strategy);
OptFunctions *optf = new OptFunctions(M,R,lrm,T,Nr);

 BFOA *bfoa = new BFOA(optf);
 int tmp = bfoa->getID();

 //int n =100;

 //http://www.cplusplus.com/forum/beginner/6596/
 //bfoa.x -> &BFOA::revenueFunction;
 //printf("%d\n",(a.*(a.x))());
 //bfoa->start(n, &BFOA.::revenueFunction);

 // https://stackoverflow.com/questions/2402579/function-pointer-to-member-function
 bfoa->setupParam(&OptFunctions::revenueFunction,n,lb,ub,dimension,iteration,Nre,Ned,Nc,Ns,C,Ped,Da,Wa,Hr,Wr,lamda,L,arga,argj,arged, search_type,search_strategy);
 bfoa->printParam();
 bfoa->start(n, &BFOA::revenueFunction);
 bfoa->process(n, &OptFunctions::revenueFunction);
 printf("%d\n",tmp);
 return 0;
}