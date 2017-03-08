#include "../inc/lehenenBatura.h"

uint32_t zerrenda[]={17,3,14,21,43,2,12};
uint32_t result;

int main()
{
  result=lehenenBatura(zerrenda, sizeof(zerrenda)/sizeof(uint32_t));
  
  while(1) {}
}

int lehenaAlDa(uint32_t n)
{
  int i=2;
    
  if(n<=1) return 0;
  while(i*i<=n)
  {
    if(n%i==0) return 0;
    i++;
  }
  return 1;
}

/*uint32_t lehenenBatura(uin32_t *pZerrenda, uint32_t dim)
{
  uint32_t n=0;
  
  while(dim>0)
  {
    if(lehenaAlDa(*pZerrenda)) n++;
    pZerrenda++;
    n--;
  }
  return n;
}
*/
