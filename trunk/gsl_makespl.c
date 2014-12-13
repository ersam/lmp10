#include "makespl.h"
#include <gsl/gsl_linalg.h>

#include <stdio.h>

void
make_spl (points_t * pts, spline_t * spl)
{

	int n= pts->n - 1;
	double *x = pts->x;
	double *y = pts->y;

	gsl_matrix *A = gsl_matrix_alloc( n*3, n*3+1 );
	gsl_permutation *p = gsl_permutation_calloc( n*3 );

	int i, signum;
	
	A->size1 = n*3;
	A->size2 = n*3+1;


	for( i= 0; i < n; i++ ) {
		double dx= x[i+1] - x[i];
		size_t if1= 3*i;
		size_t if2= if1+1;
		size_t if3= if2+1;
		gsl_matrix_set( A, if1, if1, dx );
		gsl_matrix_set( A, if1, if2, dx*dx/2 );
		gsl_matrix_set( A, if1, if3, dx*dx*dx/6 );
		gsl_matrix_set( A, if1, n*3, y[i+1]-y[i] );
		gsl_matrix_set( A, if2, if1, 1 );
		gsl_matrix_set( A, if2, if2, dx );
		gsl_matrix_set( A, if2, if3, dx*dx/2 );
		if( if3+1 < n*3 )
			gsl_matrix_set( A, if2, if3+1, -1 );
		else
			gsl_matrix_set( A, if2, if1, 0 );
		gsl_matrix_set( A, if3, if2, 1 );
		gsl_matrix_set( A, if3, if3, dx );
		if( if3+2 < n*3 )
			gsl_matrix_set( A, if3, if3+2, -1 );
	}

#ifdef DEBUG
	gsl_matrix_view_array( A->data, A->size1, A->size2 );
#endif
	if( gsl_linalg_LU_decomp( A, p, &signum ) ) {
		spl->n = 0;
		return;
	}

#ifdef DEBUG
	gsl_matrix_view_array( A->data, A->size1, A->size2 );
#endif
  if ( alloc_spl (spl, pts->n) == 0 ) {
    spl->n = pts->n;
		for( i= 0; i < n; i++ ) {
			spl->x[i]= pts->x[i];
			spl->f[i]= pts->y[i];
			spl->f1[i]= gsl_matrix_get( A, 3*i,   3*n );
			spl->f2[i]= gsl_matrix_get( A, 3*i+1, 3*n );
			spl->f3[i]= gsl_matrix_get( A, 3*i+2, 3*n );
		}
		spl->x[n]= pts->x[n];
		spl->f[n]= pts->y[n];
		spl->f1[n]= spl->f1[n-1];
		spl->f2[n]= 0;
		spl->f3[n]= 0;
  }
}