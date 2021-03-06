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

void test_for_add_to_list_for_int(){
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

void test_for_add_to_list_for_mix_data_types(){
	LinkedList list = createList();
	char ele1 = 'a';
	char ele2 = 'b';
	float ele3 = 12.523;
	double d = ele3;
	double ele4 = 1234443344;
	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	int list_length = add_to_list(&list, &ele4);
	assert(list_length == 4);
	assert(*(char *)list.first_element->value == 'a');
	assert(*(char *)list.first_element->next->value == 'b');
	assert(*(float *)list.first_element->next->next->value == d);
	assert(*(double *)list.last_element->value == 1234443344);
};
void test_check_first_element_of_list_for_int(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	void *first_ele = get_first_element(list);
	assert(*(int *)list.first_element->value == 12);
};

void test_check_first_element_of_list_for_mix_data_type(){
	LinkedList list = createList();
	char ele1 = 'a';
	double ele2 = 744463878634733;
	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	void *first_ele = get_first_element(list);
	assert(*(char *)list.first_element->value == ele1);	
};

void test_check_last_element_of_list_for_int(){
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

void test_check_last_element_of_list_for_char(){
	LinkedList list = createList();
	int ele1 = 12;
	int ele2 = 7;
	int ele3 = 'a';

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);

	void *last_ele = get_last_element(list);
	assert(*(char *)list.last_element->value == 'a');
};
void incremnt_by_one(void *ele){
	int *element = (int *)ele;
	*element = *element + 1;
};

void test_for_increment_of_each_element_by_1_of_list_for_int(){
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

void test_for_increment_of_each_element_by_1_charachter_of_list_for_char(){
	LinkedList list = createList();
	char ele1 = 'a';
	char ele2 = 'b';
	char ele3 = 'c';

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	ElementProcessor e = &incremnt_by_one;
	forEach(list, e);
	assert(*((char *)list.first_element->value) == 'b');
	assert(*((char *)list.last_element->value) == 'd');
};
void test_for_get_element_at_valid_index_for_int(){
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

void test_for_get_element_at_valid_index_for_char(){
	LinkedList list = createList();
	char ele1 = 'a';
	char ele2 = 'b';
	char ele3 = 'c';

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	void  *ele = getElementAt(list, 0);
	Element *e = (Element *)ele;
	assert(*((char *)e->value) == 'a');
	ele = getElementAt(list, 2);
	e = (Element *)ele;
	assert(*((char *)e->value) == 'c');
};

void test_for_get_element_at_valid_index_for_mix_data_type(){
	LinkedList list = createList();
	float ele1 = 1223.5;
	char ele2 = 'b';
	double ele3 = 122232437384373;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	void  *ele = getElementAt(list, 0);
	Element *e = (Element *)ele;
	assert(*((float *)e->value) == ele1);
	ele = getElementAt(list, 2);
	e = (Element *)ele;
	assert(*((double *)e->value) == ele3);
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

void test_for_index_of_method_for_valid_elements_for_int(){
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

void test_for_index_of_method_for_valid_elements_for_char(){
	LinkedList list = createList();
	int ele1 = 12;
	char ele2 = 'c';
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);

	int index = indexOf(list,&ele2);
	assert(index == 1);
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

void test_for_deleteElementAt_valid_index_for_int(){
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

void test_for_deleteElementAt_valid_index_for_mix_data_type(){
	LinkedList list = createList();
	char ele1 = 'a';
	float ele2 = 7.235;
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

void test_for_filter_in_linkedList_for_int(){
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
};

void test_for_filter_in_linkedList_for_mix_data_type(){
	LinkedList list = createList();
	int ele1 = 2;
	char ele2 = 'a';
	float ele3 = 8.53435;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	int hint = 2;
	MatchFunc *match_func = &checkEven; 
	LinkedList filtered_list = filter(list, match_func,&hint);
	assert(filtered_list.number_of_elements == 1);
	int first_ele = *(int *)filtered_list.first_element->value;
	assert(first_ele == 2);
	int last_ele = *(int *)filtered_list.last_element->value;
	assert(last_ele == 2);
};

void test_for_reverse_method_in_linkedList(){
	LinkedList list = createList();
	int ele1 = 2;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	LinkedList reversedList = reverse(list);
	int first_ele = *(int *)reversedList.first_element->value;
	assert(first_ele == 8);
	int last_ele = *(int *)reversedList.last_element->value;
	assert(last_ele == 2);
	assert(reversedList.number_of_elements == 3);
};

void test_for_reverse_method_in_linkedList_for_mix_data_type(){
	LinkedList list = createList();
	int ele1 = 2;
	char ele2 = 'a';
	float ele3 = 2.455;
	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	LinkedList reversedList = reverse(list);
	float first_ele = *(float *)reversedList.first_element->value;
	assert(first_ele == ele3);
	int last_ele = *(int *)reversedList.last_element->value;
	assert(last_ele == 2);
	assert(reversedList.number_of_elements == 3);
};

void incremnt_by_hint(void* hint, void * sourceItem, void *destinationItem){
	int source = *(int *)sourceItem;
	int num = *(int *)hint;
	*(int *)destinationItem = num + source;
};

void test_for_map_in_LinkedList_for_int(){
	LinkedList list = createList();
	int ele1 = 2;
	int ele2 = 7;
	int ele3 = 8;
	int ele4 = 9;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	add_to_list(&list, &ele4);
	int hint = 5;
	ConvertFunc *convertor = &incremnt_by_hint;
	LinkedList mapped_list = map(list, convertor, &hint);
	assert(*(int *)mapped_list.last_element->value == 14);
	assert(*(int *)mapped_list.first_element->value == 7);
	assert(mapped_list.number_of_elements == 4);
};

void test_for_map_in_LinkedList_for_char(){
	LinkedList list = createList();
	char ele1 = 'a';
	char ele2 = 'b';
	char ele3 = 'c';
	char ele4 = 'd';

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	add_to_list(&list, &ele4);
	char hint = 5;
	ConvertFunc *convertor = &incremnt_by_hint;
	LinkedList mapped_list = map(list, convertor, &hint);
	assert(*(char *)mapped_list.last_element->value == 'i');
	assert(*(char *)mapped_list.first_element->value == 'f');
	assert(mapped_list.number_of_elements == 4);
};

void test_for_asArray(){
	LinkedList list = createList();
	int ele1 = 2;
	int ele2 = 7;
	int ele3 = 8;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	void  *array[5];
	int arr_length = asArray(list,array, 3);
	assert(arr_length == 3);
	assert(*(int *)array[0] = 2);
	assert(*(int *)array[arr_length-1] = 8);
};

void *getGreatest(void* hint, void* previousItem, void* item){
	int previousVlaue = *(int *)previousItem;
	int nextValue = *(int *)item;
	if(nextValue > previousVlaue){
		previousItem = item;
	}
	return previousItem;
};

void test_for_reduce_in_linkedLink(){
	LinkedList list = createList();
	int ele1 = 2;
	int ele2 = 7;
	int ele3 = 8;
	int ele4 = 12;

	add_to_list(&list, &ele1);
	add_to_list(&list, &ele2);
	add_to_list(&list, &ele3);
	add_to_list(&list, &ele4);
	int hint = 4;
	int initialValue = 1;
	Reducer *reduced_func = &getGreatest;
	void *reduced_ele = reduce(list, reduced_func, &hint, &initialValue);
	assert(*(int *)reduced_ele = 12	);
};

int main(){
	test_for_create();
	test_for_add_to_list_for_int();
	test_for_add_to_list_for_mix_data_types();
	test_check_first_element_of_list_for_int();
	test_check_first_element_of_list_for_mix_data_type();
	test_check_last_element_of_list_for_int();
	test_check_last_element_of_list_for_char();
	test_for_increment_of_each_element_by_1_of_list_for_int();
	test_for_increment_of_each_element_by_1_charachter_of_list_for_char();
	test_for_get_element_at_valid_index_for_int();
	test_for_get_element_at_valid_index_for_char();
	test_for_get_element_at_valid_index_for_mix_data_type();
	test_for_get_element_at_invalid_index();
	test_for_index_of_method_for_valid_elements_for_int();
	test_for_index_of_method_for_valid_elements_for_char();
	test_for_index_of_method_for_invalid_elements();
	test_for_deleteElementAt_valid_index_for_int();
	test_for_deleteElementAt_valid_index_for_mix_data_type();
	test_for_deleteElementAt_invalid_index();
	test_for_filter_in_linkedList_for_int();
	test_for_filter_in_linkedList_for_mix_data_type();
	test_for_reverse_method_in_linkedList();
	test_for_reverse_method_in_linkedList_for_mix_data_type();
	test_for_map_in_LinkedList_for_int();
	test_for_map_in_LinkedList_for_char();
	test_for_asArray();
	test_for_reduce_in_linkedLink();
}