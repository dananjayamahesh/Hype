#include <stdio.h>
#include "headers/BFOA.h"

BFOA::BFOA(){
       id = 1;
       printf("%s\n","Constructor");
}
BFOA::~BFOA(){
	id =0;
	printf("%s\n","Virtual Destructor");
}
int BFOA::getID(){
       return id;
}
