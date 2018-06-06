#include <stdio.h>
#include "headers/Population.h"

//Generic Classes
//https://www.tutorialspoint.com/cplusplus/cpp_templates.htm
//template <class T>
//Population <T>::Population(int n, int lb ,	int ub ,int dimension){
Population ::Population(int n, int lb ,	int ub ,int dimension){
  printf("%s with Population Size %d\n", "Initializing Population Class",n);
  this->n = n;
  this->lb = lb;
  this->ub = ub;
  this->dimension = dimension;
  //this-> 
}

//template <class T>
Population ::~Population(){
	printf("%s\n", "Population Destruction");
}

