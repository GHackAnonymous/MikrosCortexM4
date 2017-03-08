#include "../inc/faktorial.h"

int n=7, m=3;
int cnm;

int main()
{
  uint32_t nF,mF,nmF;
	
  nF=factorial(n);
  mF=factorial(m);
  nmF=factorial(n-m);
  cnm=nF/mF/nmF;
	while(1){}
}
