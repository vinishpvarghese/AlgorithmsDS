
typedef struct myQueue{

    int front;
    int rear;
    int size;
    int capacity;
    int * arr ;//Q

}myQueue;


typedef struct graphArrnode{
	int dest;
	int weight;
	struct graphArrnode* next;
}graphArrnode;

typedef struct graphArrList 
{
	graphArrnode * head;
}graphArrList;



typedef struct _graph{
	
	int num;
	graphArrList* ArrList;
	
}graph;
