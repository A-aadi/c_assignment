
typedef struct element{
 	void *vlaue;
 	struct element *next;
}Element;

typedef struct{
	Element *first_element;
	Element *last_element;
	int number_of_elements;
}LinkedList;

LinkedList createList(void);