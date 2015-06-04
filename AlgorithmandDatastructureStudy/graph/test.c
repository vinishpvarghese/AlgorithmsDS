#include <stdio.h>
#include "graph.h"

int main()
{
    /* test */
	int i,j,k,l,m,n;
	int exit = 1;
	int dir = 0;
	graph* gr=NULL;
	myQueue * q = NULL;
	while(exit)
	{
		printf("\nTEST MENU\n");
		printf("*********\n");
		printf("1.Create and print a graph\n");
		printf("2.DFS\n");
		printf("5.Exit\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1:
				printf("Enter no of nodes\n");
				scanf("%d",&k);
				printf("Enter 0:UnDirected 1:Directed\n");
				scanf("%d",&dir);
				gr=(graph*)createGraph(k);
	//			addVertices(gr,0,1,dir,1);
				addVertices(gr,0,4,dir,4);
				addVertices(gr,1,2,dir,2);
				addVertices(gr,1,3,dir,3);
				addVertices(gr,1,4,dir,4);
				addVertices(gr,2,3,dir,3);
				addVertices(gr,3,4,dir,4);
				printGraph(gr);
				break;
			case 2:
				graph_DFS(gr,0);
				break;
			case 3:
				q = createQ(10);
				enQ(q,1);
				enQ(q,3);
				enQ(q,5);
				deQ(q);
				enQ(q,7);
				enQ(q,9);
				enQ(q,11);
				deQ(q);
				deQ(q);
				deQ(q);


				break;
			case 5:
				exit = 0;
				break;
		}

	}


    return 0;
}
