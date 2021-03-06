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
	if(list->number_of_elements == 0){
		list->first_element = list->last_element = e;
		
	}else{
		list->last_element->next = e;
		list->last_element = e;
	}
	list->number_of_elements++;
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
			return list.first_element;
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

void * deleteElementAt(LinkedList *list, int index){
	void * actual_ele = getElementAt(*list, index);
	Element * next_ele = (Element *)getElementAt(*list, index+1);
	Element * previous_ele = (Element *)getElementAt(*list, index-1);
	if(actual_ele != NULL){
		for(int i=index; i < list -> number_of_elements; i++){
			if(index != 0)
				previous_ele->next = actual_ele = next_ele;
			else
				actual_ele = list->first_element= next_ele;
		};
		list->number_of_elements--;
	};
	return actual_ele;
};

LinkedList filter(LinkedList list,  MatchFunc *match_func, void * hint){
	LinkedList filtered_list = createList();
	for(int i =0; i<list.number_of_elements; i++){
		if(match_func(list.first_element->value,hint)==1)
			add_to_list(&filtered_list, list.first_element->value);
		list.first_element = list.first_element->next;
	}
	return filtered_list;
};

LinkedList reverse(LinkedList list){
	LinkedList reversed_list = createList();
	for(int i = list.number_of_elements-1; i>=0; i--){
		Element *ele = (Element *)getElementAt(list,i);
		// printf("%d\n", );
		add_to_list(&reversed_list, ele->value);
	}
	return reversed_list;
};

LinkedList map(LinkedList list, ConvertFunc *convertor,void *hint){
	LinkedList mapped_list = createList();
	for(int i = 0; i<list.number_of_elements; i++){
		void *value = malloc(sizeof(void *));
		convertor(hint, list.first_element->value, value);
		add_to_list(&mapped_list,  value);
		list.first_element = list.first_element->next;
	};
	return mapped_list;
};

int asArray(LinkedList list, void ** arr, int maxElements){
	int counter = 0;
	Element *list_ele = list.first_element;
	for(int i =0; i<maxElements; i++){
		if(list_ele == NULL)
			return counter;
		arr[counter] = list_ele->value;
		list_ele = list_ele->next;
		counter++;
	}
	return counter;
};

void * reduce(LinkedList list, Reducer reduced_func, void *hint, void *initialValue){
	void * previousValue = initialValue;
	for(int i = 0; i < list.number_of_elements; i++){
		void* reduced_item = reduced_func(&hint, previousValue,list.first_element->value);
		list.first_element = list.first_element->next;
		previousValue = reduced_item;
	}
	return previousValue;

}

