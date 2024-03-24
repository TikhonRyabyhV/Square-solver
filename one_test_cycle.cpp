#include <stdio.h>
#include <math.h>

#include "square_solver.h"
#include "data_list.h"
#include "help_functions.h"

int one_test_cycle( data_list_st* now_member, int all_tests ) {
	
	double x1 = NAN;
	double x2 = NAN;

	int n = ERROR;
	int return_ = square_solver( now_member->a, now_member->b, now_member->c, &x1, &x2, &n );

	printf( "Test %d ( a = %7.3lf, b = %7.3lf, c = %7.3lf ):", all_tests, now_member->a, now_member->b, now_member->c );

	
	if( !cmp_for_double( x1, now_member->right_x1 ) || !cmp_for_double( x2, now_member->right_x2 ) ||
	n != now_member->right_n  || return_ != now_member->right_return ) { 
		
		printf( " faild. Should be: return = %d, n = %d, x1 = %7.3lf, x2 = %7.3lf,\n"
			" but return = %d, n = %d, x1 = %7.3lf, x2 = %7.3lf.\n\n",
			now_member->right_return, now_member->right_n, now_member->right_x1,
			now_member->right_x2, return_, n, x1, x2 );

		return 0;
	}

	printf( " success. n = %d, x1 = %7.3lf, x2 = %7.3lf. \n", n, x1, x2 );

	return 1;
}
