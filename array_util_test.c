#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "array_utils.h"

void create_array(){
	Array_util a = create(sizeof(int),5);
	assert(a.type_size == 4);
	assert(a.length == 5);
	free(a.base);
};

void array_are_equal(){
	Array_util a = create(sizeof(int), 6);
	Array_util b = create(sizeof(int), 6);
	int * arr1 = (int *)a.base;
	int * arr2 = (int *)b.base;
	arr1[0] = 12;
	arr2[0] = 11;
	int res = are_equal(a,b);
	assert(res == 0);
	arr1[0] = 12;
	arr2[0] = 12;
	res = are_equal(a,b);
	assert(res == 1);
	free(a.base);
	free(b.base);
};

void check_equal_in_str_case(){
	Array_util a = create(sizeof(char), 2);
	Array_util b = create(sizeof(char), 2);
	char *arr1 = a.base;
	char *arr2 = b.base;
	// arr1 = "wow";
	// arr2 = "wow";
	// int res = are_equal(a,b);
	// assert(res == 1);
	arr1 = "wow";
	arr2 = "mom";
	int res = are_equal(a,b);
	assert(res == 1);
	free(a.base);
	free(b.base);
};

void resize_array(){
	Array_util a = create(sizeof(int) , 4);
	Array_util util = resize(a , 3);
	assert(util.length == 3);
	assert(util.type_size == 4);
	util = resize(a , 2);

	int *arr = util.base;
	arr[0] = 12;
	arr[1] = 11;
	// arr[2] = 10;
	// arr[4] = 9;
	// arr[3] = 8;

	// for (int i = 0; i < 2; ++i)
	// {
	// 	printf("%d\n",arr[i] );
	// }
	assert(util.length == 2);
	free(a.base);
};

void check_index_for_float(){
	Array_util a = create(sizeof(int), 5);
	float *arr1 = a.base;
	arr1[0]=12.2353;
	arr1[1]=13.1;
	arr1[2]=14.12;
	arr1[3]=15.22;
	float x = 12.2353;
	int index = findIndex(a, &x);
	assert(index == 0);
	x = 12.2350;
	index = findIndex(a, &x);
	assert(index == -1);
};

void check_index_for_char(){
	Array_util a = create(sizeof(char), 4);
	char *arr = a.base;
	arr[0] = 'a';
	arr[1] = 'b';
	arr[2] = 'c';
	char x = 'b';
	int index = findIndex(a, &x);
	assert(index == 1);
};

void check_divisibility_if_divisible_for_findFirst(){
	Array_util a = create(sizeof(int), 4);
	int *arr = a.base;
	arr[0] = 12;
	arr[1] = 13;
	arr[2] = 14;
	arr[3] = 15;
	arr[4] = 16;

	int hint = 4;
	MatchFunc *match = &isDivisible;
	void * find = findFirst(a, match, &hint); 
	int res = *(int *)find;
	assert(res == 12);
};

void check_divisibility_if_divisible_for_findLast(){
	Array_util a = create(sizeof(int), 4);
	int *arr = a.base;
	arr[0] = 12;
	arr[1] = 13;
	arr[2] = 14;
	arr[3] = 15;
	arr[4] = 16;

	int hint = 4;
	MatchFunc *match = &isDivisible;
	void * find = findLast(a, match, &hint); 
	int res = *(int *)find;
	assert(res == 16);
};

void check_divisibility_if_not_divisible_for_findFirst(){
	Array_util a = create(sizeof(int), 4);
	int *arr = a.base;
	arr[0] = 12;
	arr[1] = 13;
	arr[2] = 14;
	arr[3] = 15;

	int hint = 41;
	MatchFunc *match = &isDivisible;
	void * find = findFirst(a, match, &hint); 
	assert(find == NULL);
};


int main(){
	create_array();
	array_are_equal();
	resize_array();
	check_equal_in_str_case();
	check_index_for_float();
	check_index_for_char();
	check_divisibility_if_divisible_for_findFirst();
	check_divisibility_if_not_divisible_for_findFirst();
	check_divisibility_if_divisible_for_findLast();
	return 0;
};



