#include "in_output.h"
#include "square_solver.h"
#include "breakers.h"

int input ( double* a, double* b, double* c ) {

	func_breaker( a != NULL );
	func_breaker( b != NULL );
	func_breaker( c != NULL );

	printf( "Please enter a, b, c ( with spaces ):\n" );

	char data_str[MAX_SIZE] = "";

	if( fgets( data_str, MAX_SIZE, stdin ) == NULL ) {
		printf( "Data read error.\n" );
		return 2;
	}

	int fields = sscanf( data_str, "%lf %lf %lf", a, b, c );

	if( fields == 3 )
		return 0;

	printf( "Incorrect data: you should enter three real numbers.\n"
	     	"Do you want to continue ( y / n )?  " );

	char choise = 'n';

	if( fgets( data_str, MAX_SIZE, stdin ) == NULL ) {
		printf( "Data read error.\n" );
		return 2;
	}

	sscanf( data_str, "%c", &choise );

	if( choise == 'y' )
		return -1;
	else
		return 1;

}


int output ( const double x1, const double x2, const int n ) {

	func_breaker( n != ERROR );

	if( !n ) {
		printf( "Result: no roots.\n" );
		return 0;
	}
	if( n == INFINITY_ROOTS ) {
		printf( "Result: infinity roots.\n" );
		return 0;
	}
	if( n == 1 ) {
		func_breaker( isfinite( x1 ) );

		printf( "Result: x = %.3lf.\n", x1 );
		return 0;
	}
	if( n == 2 ) {
		func_breaker( isfinite( x1 ) );
		func_breaker( isfinite( x2 ) );

		printf( "Result: x1 = %.3lf, x2 = %.3lf.\n", x1, x2 );
		return 0;
	}

	printf( "Error: n has another value.\n" );
	return 1;
}

