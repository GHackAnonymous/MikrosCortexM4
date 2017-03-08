#include "../inc/max.h"

int x1=3, x2=7, x3=45, x4=11, result;

int main()
{
	int tmp;
	
	tmp=max(x1,x2);
	tmp=max(tmp,x3);
	result=max(tmp,x4);
	while(1){}
}

