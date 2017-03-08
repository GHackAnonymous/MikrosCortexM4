#include "../inc/arraySumRec.h"

uint32_t bektore[]={1,2,3,4,5,6,7,8,9};
uint32_t result;

int main()
{
	result=arraySumRec(bektore,sizeof(bektore)/sizeof(uint32_t));
	while(1){}
}

/*uint32_t arraySumRec(uint32_t *bektore, uint32_t dim)
{
	uint32_t tmp;
	
  if(dim==0) return 0;
  else 
  {
	  tmp=*bektore;
    bektore++;
    dim--
    return tmp+arrauSumRec(bektore,dim);
  }
}*/

