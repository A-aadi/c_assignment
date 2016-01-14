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

void test_for_get_element_at_valid_index(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	void  *ele = getElementAt(list, 0);
	Element *e = (Element *)ele;
	assert(*((int *)e->value) == 12);
	ele = getElementAt(list, 2);
	e = (Element *)ele;
	assert(*((int *)e->value) == 8);
};

void test_for_get_element_at_invalid_index(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	void  *ele = getElementAt(list, 10);
	assert(ele == NULL);
	ele = getElementAt(list, -1);
	assert(ele == NULL);
};

void test_for_index_of_method_for_valid_elements(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);

	int index = indexOf(list,&ele3);
	assert(index == 2);
};

void test_for_index_of_method_for_invalid_elements(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	char a = 'a';
	int index = indexOf(list,&a);
	assert(index == -1);
};

void test_for_deleteElementAt_valid_index(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	void *deleted_element = deleteElementAt(&list,0);
	assert(indexOf(list, &ele1) == -1);
	assert(list.number_of_elements == 2);
	int ele4 = 15;
	add_to_list(&list, &ele4);
	deleted_element = deleteElementAt(&list,1);	
	assert(indexOf(list,&ele3) == -1);
	deleted_element = deleteElementAt(&list,1);
	assert(indexOf(list,&ele4) == -1);

};

void test_for_deleteElementAt_invalid_index(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	void *deleted_element = deleteElementAt(&list,32);
	assert(deleted_element == NULL);
	assert(list.number_of_elements == 2);
};

int checkEven(void *item, void*hint){
	int value = *(int *)item;
	int num = *(int *)hint;
	if(value % num == 0)
		return 1;
	return 0;
};

void test_for_filter_in_linkedList(){
	LinkedList list = createList();
	int ele1 = 2;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	int hint = 2;
	MatchFunc *match_func = &checkEven; 
	LinkedList filtered_list = filter(list, match_func,&hint);
	assert(filtered_list.number_of_elements == 2);
	int first_ele = *(int *)filtered_list.first_element->value;
	assert(first_ele == 2);
	int last_ele = *(int *)filtered_list.last_element->value;
	assert(last_ele == 8);
}

int main(){
	test_for_create();
	test_for_add_to_list();
	test_check_first_element_of_list();
	test_check_last_element_of_list();
	test_for_increment_of_each_element_by_1_of_list();
	test_for_get_element_at_valid_index();
	test_for_get_element_at_invalid_index();
	test_for_index_of_method_for_valid_elements();
	test_for_index_of_method_for_invalid_elements();
	test_for_deleteElementAt_valid_index();
	test_for_deleteElementAt_invalid_index();
	test_for_filter_in_linkedList();
}