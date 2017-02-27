#include "../inc/sumArray.h"

uint32_t bektore []={1,2,3,4,5,6,7,8,9};
uint32_t result;

int main(){
	result = sumArray( *bektore, sizeof(bektore)/sizeof(uint32_t));
	while(1){}
}