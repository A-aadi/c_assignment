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

void test_for_add_to_list(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;
	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	int list_length = add_to_list(&list, &ele3);
	assert(list_length == 3);
	assert(*(int *)list.first_element->value == 12);
	assert(*(int *)list.first_element->next->value == 7);
	assert(*(int *)list.last_element->value == 8);
};

int main(){
	test_for_create();
	test_for_add_to_list();
}