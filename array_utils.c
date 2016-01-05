#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_utils.h"

// -----------------------------------------------------------------------------------

Array_util create(int type_size, int length){
	void *new_array = calloc(length , type_size);
	Array_util new_util ;
	new_util.base = new_array;
	new_util.type_size = type_size;
	new_util.length = length;
	return new_util;
};

// -----------------------------------------------------------------------------------

int are_equal(Array_util a, Array_util b){
	int ret = memcmp(a.base , b.base ,a.length * a.type_size);
	if(a.length != b.length || ret!=0)
		return 0;
	return 1;
};

// -----------------------------------------------------------------------------------

Array_util resize(Array_util util , int length){
	util.base = realloc(util.base, util.type_size*length);
	util.length = length;
	return util;
};

// -----------------------------------------------------------------------------------

int findIndex(Array_util util, void *element){
	int size_of_a_element = util.type_size;
	void *base = util.base;
	for (int i = 0; i < util.length; ++i)
	{
		int comparison = memcmp(base, element, size_of_a_element);
		if(comparison == 0)
			return i;
		base = base + size_of_a_element;
	};
	return -1;
};

// -----------------------------------------------------------------------------------

void dispose(Array_util a){
	free(a.base);
};

// -----------------------------------------------------------------------------------

int isDivisible(void *hint, void *item){
	int a = *(int *)hint;
	int b = *(int *)item;
	if(b%a == 0)
		return 1;
	return 0;
};

// -----------------------------------------------------------------------------------

void* findFirst(Array_util util, MatchFunc* match, void* hint){
	void *base = util.base;
	int size_of_a_element = util.type_size;
	for (int i = 0; i < util.length; ++i)
	{
		if(match(hint, base))
			return base;
		base = base + size_of_a_element;
	};
	return (void *)NULL;
};

// -----------------------------------------------------------------------------------

void *findLast(Array_util util, MatchFunc *match, void *hint){
	void *base = util.base + (util.type_size * util.length);
	int size_of_a_element = util.type_size;
	for (int i = 0; i < util.length; ++i)
	{
		if(match(hint, base))
			return base;
		base = base - size_of_a_element;
	}
	return (void *)NULL;
};

// -----------------------------------------------------------------------------------

int count(Array_util util, MatchFunc* match, void* hint){
	void *base = util.base;
	int size_of_a_element = util.type_size;
	int count = 0;
	for (int i = 0; i < util.length; ++i)
	{
		if(match(hint, base))
			count++;
		base = base + size_of_a_element;
	};
	return count;
};





