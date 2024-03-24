#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct data_list {
	int right_return;
	int right_n;
	double a;
	double b;
	double c;
	double right_x1;
	double right_x2;
	struct data_list* next;
} data_list_st; /* declaration of a list structure for tests */

int create_new_member ( data_list_st**, int, int, double, double, double, double, double );

int clean_list ( data_list_st* );
