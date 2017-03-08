#include "../inc/ourStrLen.h"

uint32_t n;

int main()
{
  n=ourStrLen("abcde");
  n+=ourStrLen("123456");
  while(1) {}
}

/*uint32_t ourStrLen(char* pStr)
{
  uint32_t n=0;
  
  while(*pStr!=0)
  {
    n++;
    pStr++;
  }
  return n;
}*/
