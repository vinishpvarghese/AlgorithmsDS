#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

#define PRINT printf



myQueue * createQ(int capacity)
{
     myQueue * q = (myQueue *)malloc(sizeof(myQueue));
     q->arr = (int *)malloc(capacity * sizeof(int));
     q->front = 0;
     q->rear = capacity-1;
     q->size = 0;
     q->capacity = capacity;

     PRINT("Queue created with Capacity %d \n",capacity);
     return q;
}

void enQ(myQueue * q,int val)
{
    if(NULL == q)
    {
        return;
    }
    if(q->size == q->capacity)
    {
	PRINT("Queue Full\n");
        return;
    
    }
    else
    {
	q->rear = (q->rear+1) % (q->capacity);
        q->arr[q->rear] = val;
	q->size++;
	PRINT("%d EnQueued\n",val);
        return;
    }

}
int deQ(myQueue * q)
{
    int retVal = INT_MIN;
    if(NULL == q)
    {
        return INT_MIN;
    }
    if(q->size != 0)
    {
         retVal = q->arr[q->front];
	 q->front = (q->front+1) % (q->capacity);
	 q->size--;
         
         PRINT("%d DeQueued\n",retVal);	 
         return retVal;
    
    }

}



graph *
createGraph (int nodes)
{
  int i = 0;
  graph *gr = (graph *) malloc (sizeof (graph));
  gr->num = nodes;
  gr->ArrList = (graphArrList *) malloc (nodes * sizeof (graphArrList));
  for (i = 0; i < nodes; i++)
    {
      gr->ArrList[i].head = NULL;
    }
	return gr;
}

void
addVertices (graph * gr, int src, int dest,int isDirected,int weight)
{
  graphArrnode *node = NULL;

  if (gr == NULL)
    {
      return;
    }

  if (gr->num == 0)
    {
      return;
    }
  if (gr->ArrList == NULL)
    {
      gr->ArrList = (graphArrList *) malloc (gr->num * sizeof (graphArrList));
    }

  node = (graphArrnode *) malloc (sizeof (graphArrnode));
  node->dest = dest;
  node->weight = weight;
  node->next = gr->ArrList[src].head;
  gr->ArrList[src].head = node;

  
  if(!isDirected)
  {
      node = (graphArrnode *) malloc (sizeof (graphArrnode));
      node->dest = src;
      node->next = gr->ArrList[dest].head;
      gr->ArrList[dest].head = node;
  }



}

void
printGraph (graph * gr)
{
  int i;
  graphArrnode *temp;

  if (gr == NULL)
    {
      return;
    }
  if (gr->num == 0)
    {
      PRINT ("Nothing to print\n");
    }
  if (gr->ArrList == NULL)
    {
      PRINT ("ERR..No adjacency list found\n");
      return;
    }
  for (i = 0; i < gr->num; i++)
    {
      temp = gr->ArrList[i].head;
      PRINT ("\n");
      PRINT ("%d :", i);
      while (temp != NULL)
	{

	  PRINT ("%d ", temp->dest);
	  temp = temp->next;
	}
    }
  return;

}

void doDFS(graph * gr,int origin,int * visitFlag)
{
    graphArrnode * node = NULL; 
    visitFlag[origin] = 1;
    node = gr->ArrList[origin].head ;
    PRINT("Visited Node %d \n",origin);

    while(node != NULL)
    {
	 if(visitFlag[node->dest] == 0)
	 {
              doDFS(gr,node->dest,visitFlag);
	 }
	 node = node->next;
    }

 }


void graph_DFS(graph * gr,int origin)
{
	int i = 0;
	int * visitFlag = (int *)malloc(gr->num *sizeof(int));
	memset(visitFlag,0,gr->num);

	doDFS(gr,origin,visitFlag);
	for(i = 0 ; i < gr->num ; i++)
	{
		if(visitFlag[i]==0)
		{
			doDFS(gr,i,visitFlag);
		}
	}
}	
