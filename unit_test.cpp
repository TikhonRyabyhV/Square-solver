#include <stdio.h>

#include "data_list.h"
#include "file_input.h"
#include "test.h"

int main( void ) {
	
	data_list_st* entries = NULL;

	int error = file_input( "test_file.txt", &entries ); 
	
	if( error )
		return 1;
	
	int suc_tests = 0, all_tests = 0;

	data_list_st* last_member = entries;

	while( entries != NULL ) {
		
		suc_tests += one_test_cycle( entries, all_tests + 1 );
		++ all_tests;

		entries = entries->next;

	}

	error = clean_list( last_member );

	if( error )
		return 1;

	printf( "So, there are %d successful tests out of all %d.\n", suc_tests, all_tests );

	return 0;
}
