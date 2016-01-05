
#define True 1
#define False 0


typedef struct{
	void *base;
	int length;
	int type_size;
}Array_util;

typedef int(MatchFunc)(void*, void*);

Array_util create(int, int);
int are_equal(Array_util , Array_util);
Array_util resize(Array_util, int);
int findIndex(Array_util, void*);
// void dispose(ArrayUtil);	
int isDivisible(void*, void*);
void* findFirst(Array_util, MatchFunc*, void*);
void* findLast(Array_util, MatchFunc*, void*);
