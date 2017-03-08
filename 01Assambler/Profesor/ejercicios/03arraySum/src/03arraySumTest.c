#include "../inc/arraySum.h"

uint32_t bektore[]={1,2,3,4,5,6,7,8,9};
uint32_t result;

int main()
{
	result=arraySum(bektore,sizeof(bektore)/sizeof(uint32_t));
	while(1){}
}

/*uint32_t arraySum(uint32_t *bektore, uint32_t dim)
{
	uint32_t sum=0;
	
	while(dim>0)
	{
		sum+=*bektore;
		bektore++;
		dim--;
	}
	return sum;
}*/

