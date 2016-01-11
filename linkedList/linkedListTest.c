#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linkedList.h"

void test_for_create(){
	LinkedList list = createList();
	assert(list.first_element == NULL);
	assert(list.last_element == NULL);
	assert(list.number_of_elements == 0);
};

int main(){
	test_for_create();
	return 0;
};