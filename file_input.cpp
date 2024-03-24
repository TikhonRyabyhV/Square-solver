#include <stdio.h>
#include <math.h>

#include "data_list.h"
#include "breakers.h"
#include "square_solver.h"

int file_input ( const char* source, data_list_st** prev ) {
	func_breaker( source != NULL );
	func_breaker( prev != NULL );	

	FILE* file = fopen( source, "r" );

	func_breaker( file != NULL );

	int error = 0;
	int right_return = 0;
	int right_n = ERROR;
	double a = NAN;	
	double b = NAN;	
	double c = NAN;	
	double right_x1 = NAN;	
	double right_x2 = NAN;

	while( fscanf( file, "%d %d %lf %lf %lf %lf %lf", &right_return, &right_n, &a, &b, &c, &right_x1, &right_x2 ) != EOF ) {   
		
		error = create_new_member( prev, right_return, right_n, a, b, c, right_x1, right_x2 );

		if( error )
			return 1;

		right_return = 0;
		right_n = ERROR;
		a = NAN;	
		b = NAN;	
		c = NAN;	
		right_x1 = NAN;	
		right_x2 = NAN;
	}

	fclose( file );

	return 0;
}
