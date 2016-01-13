#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

LinkedList createList(void){
	LinkedList list;
	list.first_element = NULL;
	list.last_element = NULL;
	list.number_of_elements = 0;
	return list;
};

int add_to_list(LinkedList *list, void *ele){
	Element *e = (Element *)malloc(sizeof(Element));

	e->value = ele;
	e->next = NULL;
	if(list->first_element == NULL){
		list->first_element = list->last_element = e;
		
	}else{
		list->last_element->next = e;
		list->last_element = e;
	}
	list->number_of_elements += 1;
	return list->number_of_elements;
};

void *get_first_element(LinkedList list){
	return list.first_element;
};

void *get_last_element(LinkedList list){
	return list.last_element;
};


void forEach(LinkedList list, ElementProcessor e){
	for (int i = 0; i < list.number_of_elements; ++i){
		e(list.first_element->value);
		list.first_element = list.first_element -> next;
	};
};

void * getElementAt(LinkedList list, int index){
	int count = 0;
	for(int i = 0; i < list.number_of_elements;i++){
		if(count == index)
			return list.first_element->value;
		count++;
		list.first_element = list.first_element->next;
	}
	return NULL;
};

int indexOf(LinkedList list, void *ele){
	int count = 0;
	for(int i = 0; i < list.number_of_elements;i++){
		if(list.first_element ->value == ele)
			return count;
		count++;
		list.first_element = list.first_element->next;
	};
	return -1;
};



