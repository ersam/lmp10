#include <stdio.h>
#include <stdlib.h>

#define MAX 7
#define MIN 6

int main()
{
	FILE *f1 = fopen("dane2", "w"), *f2 = fopen("dane3", "w");
	int i, j;

	for ( i = 2; i < 50; i++ ) {
		fprintf(f1,"%g %g\n", 0.1*i, 1.0*i*rand()/RAND_MAX);
		fprintf(f2,"%g %g\n", 0.1*i, -1.2*i*rand()/RAND_MAX);
	}

	return 0;
}
