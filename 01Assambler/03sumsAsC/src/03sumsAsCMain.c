#include "../inc/sum.h"

int x1=7, x2=3, x3=45, x4=11, result;

int main()
{
	int tmp;
	
	tmp=sum(x1,x2);
	tmp=sum(tmp,x3);
	result=sum(tmp,x4);
	while(1){}
}

