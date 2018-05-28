#include "headers/Population.h"
#include <stdio.h>
//Generic Classes
//https://www.tutorialspoint.com/cplusplus/cpp_templates.htm
template <class T>
Population <T>::Population(int pop_size){
  printf("%s with Population Size %d\n", "Initializing Population Class",pop_size);
}

template <class T>
Population <T>::~Population(){
	printf("%s\n", "Population Destruction");
}

