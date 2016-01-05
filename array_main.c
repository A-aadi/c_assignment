#include <stdio.h>
#include "array_utils.h"

int main(){
	Array_util a = create(sizeof(int), 5);
	Array_util b = create(sizeof(int), 5);

	int *arr1 = a.base;
	arr1[0]=12;
	arr1[1]=13;
	arr1[2]=14;
	arr1[3]=15;
	int hint = 9;
	MatchFunc *match = &isDivisible;
	void * find = findFirst(a, match, &hint);
	int res = *(int *)find;

	printf("%d\n", res);

	return 0;
};