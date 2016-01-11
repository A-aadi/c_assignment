typedef struct{
	void *base;
	int length;
	int type_size;
}Array_util;

typedef int(MatchFunc)(void*, void*);
typedef void(ConvertFunc)(void*, void*, void*);
typedef void(OperationFunc)(void*, void*);
typedef void*(ReducerFunc)(void*, void*, void*);

Array_util create(int, int);
int are_equal(Array_util , Array_util);
Array_util resize(Array_util, int);
int findIndex(Array_util, void*);
void dispose(Array_util);	
int isGreater(void*, void*);
int isDivisible(void*, void*);
void* findFirst(Array_util, MatchFunc*, void*);
void* findLast(Array_util, MatchFunc*, void*);
int count(Array_util, MatchFunc*, void*);

int filter(Array_util, MatchFunc*, void*, void**, int);
void increment_by_hint(void*, void*, void*);
void decrement_by_hint(void*, void*);
void map(Array_util, Array_util, ConvertFunc* , void*);
void forEach(Array_util, OperationFunc*, void*);
void* reduce(Array_util, ReducerFunc*, void*, void*);




