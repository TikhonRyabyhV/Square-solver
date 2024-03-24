#include "help_functions.h"

void greeting ( void ) {
	printf( "This program solves quadratic equations. Equation should be like this: ax^2 + bx + c = 0.\n" );

}

int cmp_for_double ( double x, double y ) {

	if( !( isfinite( x ) ) ) {

		if( !( isfinite( y ) ) )
			return 1;

		return 0;
	}

	return ( fabs( x - y ) < EPSILON );

}

