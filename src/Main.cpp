#include "headers/BFOA.h"
#include <stdio.h>


int main(){
 printf("%s\n","Hello");
 //BFOA bfoa;
 //int tmp = bfoa.getID();
 BFOA *bfoa = new BFOA();
 int tmp = bfoa->getID();
 printf("%d\n",tmp);
 return 0;
}