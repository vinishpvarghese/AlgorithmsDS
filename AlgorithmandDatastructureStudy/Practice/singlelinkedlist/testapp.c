#include <stdio.h>
#include "linkedlist.h"




int main()
{
     int exit = 0;
     int op = 0;
     int numNodes = 0;
     int nodeVal = 0;
     int nodePos = 0;
     myList * mList = NULL;

     while(!exit)
     {
     
	     printf("Enter the option\n");
	     printf("1.Craete List\n");
	     printf("2.Print List\n");
	     printf("3.Insert Node\n");
	     printf("4.Insert Node @ \n");
	     printf("5.Reverse List \n");
	     printf("0.Exit\n");

	     scanf("%d",&op);
	     switch(op)
	     {
		     case 0:
			     exit = 1;
			     break;
		     case 1:
			     printf("Enter number of Nodes\n");
			     scanf("%d",&numNodes);
			     mList = createList(numNodes);
			     break;
		     case 2:
			     printList(mList);
			     break;
		     case 3:
			     printf("Enter the Val\n");
			     scanf("%d",&nodeVal);
			     insertVal(mList,nodeVal);
			     break;
		     case 4:
			     printf("Enter the Val\n");
			     scanf("%d",&nodeVal);
			     printf("Enter the Position\n");
			     scanf("%d",&nodePos);
			     mList = insertValAt(mList,nodeVal,nodePos);
			     break;
		     case 5:
			     mList = reverseList(mList);
			     break;
		     default:
			     printf("Invalid Option\n");
			     break;

			     
	     
	     }
     }
     

     return 0;
}
