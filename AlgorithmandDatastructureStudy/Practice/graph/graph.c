#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#include "graph.h"

#define PRINT printf

graph * createGraph(int num)
{
     int i = 0;
     graph * myGraph = (graph *)malloc(sizeof(graph));

     myGraph->num = num;

     myGraph->myArrayList = (gArrayList *)malloc(num * sizeof(gArrayList));

     for(i= 0; i< num ; i++)
     {
          myGraph->myArrayList[i].head = NULL;
     }

     return myGraph;
}

void addVertices(graph * gr ,int src,int dest,int dir,int weight)
{

     graphNode * gNode = NULL;
     graphNode * gNode1 = NULL;
     if(NULL == gr)
     {
        gr = createGraph(10);
     
     }

     gNode = (graphNode*)malloc(sizeof(graphNode));

     gNode->src = src;
     gNode->dest = dest;
     gNode->weight = weight;
     gNode->next =  gr->myArrayList[src].head ;

     gr->myArrayList[src].head  = gNode;
 
     if(!dir)
     {
        gNode1 =  (graphNode*)malloc(sizeof(graphNode));

        gNode1->src = dest;
        gNode1->dest = src;
        gNode1->weight = weight;
        gNode1->next =  gr->myArrayList[dest].head ;
        gr->myArrayList[dest].head  = gNode1;
     }

}

void printGraph(graph * gr)
{

int i = 0;
graphNode * gNode = NULL;

    for(i = 0 ;i < gr->num ; i++)
    {
       gNode = gr->myArrayList[i].head;
       while(gNode)
       {
           printf("Vertices(%d,%d) with weight %d \n ",i,gNode->dest,gNode->weight );
	   gNode = gNode->next;
       
       }       
    
    }
}


void doDFS(graph * gr,int origin,int * arr)
{
     
graphNode * gNode = gr->myArrayList[origin].head;
arr[origin] = 1;
printf("Visited Node %d\n",origin);
         while(gNode)
	 {
	       if(arr[gNode->dest] == 0)
	       {
	            doDFS(gr,gNode->dest,arr);
	       }
	       gNode = gNode->next;
	 }

}

void graphDFS(graph * gr,int origin)
{

if(NULL == gr)
	return;

int * arr = (int*)calloc(gr->num,sizeof(int));
doDFS(gr,origin,arr);

}

unsigned int mindistance(unsigned int * set,unsigned int * dist,int num)
{
     unsigned int i = 0;
     unsigned int min = INT_MAX;
     unsigned int min_idx = 0;
     for(i=0;i < num;i++)
     {
         if((!set[i]) && dist[i] < min)
	 {
	     min = dist[i];
	     min_idx = i;
	 }
     }
     PRINT("min idx dist[%d] = %u\n",min_idx,dist[min_idx]);
     return min_idx;
     
}
void printDistance(unsigned int * dist,int num)
{
	unsigned int i =0;
    for(i=0;i<num;i++)
    {
       printf("dist[%d] = %u\n",i,dist[i]);
    
    }

}
void dijkstra_algo(graph * gr,int min,unsigned int * set,unsigned int *dist)
{
     int dest = 0;
     int weight = 0;

     unsigned int min_val = INT_MAX;
     unsigned int min_dest = INT_MAX;

     set[min] = 1;



     graphNode * gn = gr->myArrayList[min].head;

     while(gn)
     {
	
	     dest = gn->dest;
	     if(!set[dest])
	     {
		     weight = gn->weight;
		     if(dist[dest] >= (dist[min]+weight) )
		     {
			     dist[dest] = dist[min] + weight;
			     if(min_val  > dist[dest])
			     {
				     min_val = dist[dest];
				     min_dest = dest;
			     }
			     PRINT("dist[%d](%u) = dist[%d](%u) + %d \n",dest,dist[dest],min,dist[min],weight);
		     }
	     }
	     gn = gn->next;
     }

             PRINT("PATH %d -->\n",min_dest);
     min = mindistance(set,dist,gr->num);
     if(min)
         dijkstra_algo(gr,min,set,dist);

}
void dijkstra(graph * gr)
{
	int min = 0;
      unsigned int * set = (unsigned int *)malloc(gr->num * sizeof(int));
      unsigned int * dist = (unsigned int *)malloc(gr->num * sizeof(int));
      memset(set,0,gr->num);
      memset(dist,INT_MAX,gr->num*sizeof(int));
     printDistance(dist,gr->num);
      dist[0] = 0;
     min = mindistance(set,dist,gr->num);
      dijkstra_algo(gr,min,set,dist);

     printDistance(dist,gr->num);

}








