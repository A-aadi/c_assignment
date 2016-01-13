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

void test_check_first_element_of_list(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	void *first_ele = get_first_element(list);
	assert(*(int *)list.first_element->value == 12);
};

void test_check_last_element_of_list(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);

	void *last_ele = get_last_element(list);
	assert(*(int *)list.last_element->value == 8);
};

void incremnt_by_one(void *ele){
	int *element = (int *)ele;
	*element = *element + 1;
};

void test_for_increment_of_each_element_by_1_of_list(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	ElementProcessor e = &incremnt_by_one;
	forEach(list, e);
	assert(*((int *)list.first_element->value) == 13);
	assert(*((int *)list.last_element->value) == 9);
};

void test_for_get_element_at_valide_index(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	void  *ele = getElementAt(list, 2);
	assert(*((int *)ele) == 7);
	ele = getElementAt(list, 1);
	assert(*((int *)ele) == 12);
};

void test_for_get_element_at_invalide_index(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	void  *ele = getElementAt(list, 0);
	assert(ele == NULL);
	ele = getElementAt(list, -1);
	assert(ele == NULL);
};


int main(){
	test_for_create();
	test_for_add_to_list();
	test_check_first_element_of_list();
	test_check_last_element_of_list();
	test_for_increment_of_each_element_by_1_of_list();
	test_for_get_element_at_valide_index();
	test_for_get_element_at_invalide_index();
}