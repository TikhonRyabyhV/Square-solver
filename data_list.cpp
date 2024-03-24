#include "data_list.h"
#include "breakers.h"
#include "square_solver.h"

int create_new_member( data_list_st** prev, int right_return, int right_n, double a, double b, double c, double right_x1, double right_x2 ) {
	data_list_st* new_member = ( data_list_st* ) malloc ( sizeof( data_list_st ) );

	func_breaker( new_member != NULL );

	new_member->right_return = right_return;
	new_member->right_n = right_n;
	new_member->a = a;
	new_member->b = b;
	new_member->c = c;
	new_member->right_x1 = right_x1;
	new_member->right_x2 = right_x2;

	new_member->next = ( *prev  );

	( *prev ) = new_member;

	return 0;

}


int clean_list( data_list_st* entries ) {
	func_breaker( entries != NULL );

	data_list_st* intermed = NULL;

	while( entries != NULL ) {
		intermed = entries->next;

		free( entries );

		entries = intermed;
	}

	return 0;
}

