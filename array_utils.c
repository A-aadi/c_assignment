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
	void *base = util.base;
	for (int i = 0; i < util.length; i++){
		int comparison = memcmp(base, element, util.type_size);
		if(comparison == 0)
			return i;
		base += util.type_size;
	};
	return -1;
};

// -----------------------------------------------------------------------------------

void dispose(Array_util a){
	free(a.base);
};

// -----------------------------------------------------------------------------------

int isGreater(void *hint, void *item){
	int a = *(int *)hint;
	int b = *(int *)item;
	if(b > a)
		return 1;
	return 0;
};

// -----------------------------------------------------------------------------------

void* findFirst(Array_util util, MatchFunc* match, void* hint){
	void *base = util.base;
	for (int i = 0; i < util.length; ++i)
	{
		if(match(hint, base))
			return base;
		base += util.type_size;
	};
	return (void *)NULL;
};

// -----------------------------------------------------------------------------------

void *findLast(Array_util util, MatchFunc *match, void *hint){
	void *base = util.base + (util.type_size * util.length);
	for (int i = 0; i < util.length; ++i)
	{
		if(match(hint, base))
			return base;
		base -= util.type_size;
	}
	return (void *)NULL;
};

// -----------------------------------------------------------------------------------

int count(Array_util util, MatchFunc* match, void* hint){
	void *base = util.base;
	int count = 0;
	for (int i = 0; i < util.length; ++i)
	{
		if(match(hint, base))
			count++;
		base += util.type_size;
	};
	return count;
};

// -----------------------------------------------------------------------------------

int filter(Array_util util, MatchFunc* match, void* hint, void** destination, int maxItems){
	void *base = util.base;
	int count =0;
	for (int i = 0; i < util.length; i++){
		if(match(hint, base) == 1){
			destination[count] = base;
			count++;
		}
		base += util.type_size;
	};
	return count;
};

void map(Array_util source, Array_util destination, ConvertFunc* convert, void* hint){
	void *base = source.base;
	void *dest = destination.base; 
	for (int i = 0; i < source.length; i++){
		convert(hint, base, dest);
		base += source.type_size;
		dest += destination.type_size;
	};
};

void forEach(Array_util util, OperationFunc* operation, void* hint){
	void *base = util.base;
	for (int i = 0; i < util.length; ++i){
		operation(hint, base);
		base +=util.type_size;
	};
};

void* reduce(Array_util util, ReducerFunc* reducer, void* hint, void* initialValue){
	void * previousValue = initialValue;
	void *item = util.base;
	for (int i = 0; i < util.length; ++i){
		void* reduced_item = reducer(&hint, previousValue,item);
		previousValue = reduced_item;
		item += util.type_size;
	};
	return previousValue;
};




