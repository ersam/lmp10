#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f1 = fopen("dane2", "w"), *f2 = fopen("dane3", "w");
	int i, j;

	for ( i = 0; i < 100; i++ ) {
		fprintf(f1,"%d %g\n", i, 1.0*i*rand()/RAND_MAX);
		fprintf(f2,"%g %g\n", 0.5*i, -1.2*i*rand()/RAND_MAX);
	}

	return 0;
}
