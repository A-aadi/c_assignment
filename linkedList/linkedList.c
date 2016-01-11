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

