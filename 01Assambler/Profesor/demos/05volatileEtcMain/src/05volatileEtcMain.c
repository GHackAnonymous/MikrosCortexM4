#include <stdint.h>

int handiena(int a, int b, int c, int d, int e);

int main (void)
{
	volatile int a,b,c,d,e;
	volatile int z;
	a = b = c = d = e = 0;
	for (;;)
	{
		a++;
		b = a*a;
		c = -a;
		d = b + c;
		e = a - b;
		z = handiena(a,b,c,d,e);
	}
}

int handiena(int a, int b, int c, int d, int e)
{
	if( a < b ) a = b;
	if( a < c ) a = c;
	if( a < d ) a = d;
	if( a < e ) a = e;
	return a;
}

/*

Sinifica que esteas variables en ningun caso se mantendran mas
de lo necesario (gunto para hacer una peracion) en los registros
una vez echo las operaciones luego se guarda de nuevo en menoria.

*/
