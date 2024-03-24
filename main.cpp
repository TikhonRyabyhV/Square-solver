#include <stdio.h>
#include <math.h>

#include "in_output.h"
#include "help_functions.h"
#include "square_solver.h"

int main ( void ) {
	greeting();

	int errors = -1;
	double a = NAN, b = NAN, c = NAN;

	while( errors == -1 )
		errors = input( &a, &b, &c );
	
	if( errors )
		return 1;

	int n = ERROR;
	double x1 = NAN, x2 = NAN;

	errors = square_solver( a, b, c, &x1, &x2, &n );

	if( errors )
		return 1;

	errors = output( x1, x2, n );

	if( errors )
		return 1;

	return 0;
}
