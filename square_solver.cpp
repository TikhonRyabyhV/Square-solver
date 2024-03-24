#include "breakers.h"
#include "help_functions.h"
#include "square_solver.h"

int square_solver ( const double a, const double b, const double c, double* x1, double* x2, int *n ) {
	
	func_breaker( isfinite( a ) );
	func_breaker( isfinite( b ) );
	func_breaker( isfinite( c ) );

	func_breaker( x1 != NULL );
	func_breaker( x2 != NULL );
	func_breaker( n != NULL );
	func_breaker( x1 != x2 );

	if( cmp_for_double( a, 0 ) ) {
		if( cmp_for_double( b, 0 ) ) {
			if( cmp_for_double( c, 0 ) ) {
				( *n ) = INFINITY_ROOTS;
				return 0;
			}
			( *n ) = 0;
			return 0;
		}
		( *n ) = 1;

		( *x1 ) = - c / b;
		if( cmp_for_double( *x1, 0 ) )
			( *x1 ) = 0;

		return 0;
	}

	double D = b * b - 4 * a * c;

	if( D < 0 ) {
		( *n ) = 0;
		return 0;
	}

	( *n ) = 2;

	( *x1 ) = - ( b + sqrt( D ) ) / ( 2 * a );
	if( cmp_for_double( *x1, 0 ) )
			( *x1 ) = 0;

	( *x2 ) = - ( b - sqrt( D ) ) / ( 2 * a );
	if( cmp_for_double( *x2, 0 ) )
			( *x2 ) = 0;

	return 0;
}
