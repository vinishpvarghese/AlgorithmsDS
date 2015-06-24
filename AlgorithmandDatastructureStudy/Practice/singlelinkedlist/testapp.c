#include <stdio.h>
#include "linkedlist.h"




int main()
{
     int exit = 0;
     int op = 0;
     int numNodes = 0;
     int nodeVal = 0;
     int nodePos = 0;
     int len = 0;
     bool status = false;
     int num =0;
     myList * mList = NULL;

     while(!exit)
     {
     
	     printf("Enter the option\n");
	     printf("1.Craete List\n");
	     printf("2.Print List\n");
	     printf("3.Insert Node\n");
	     printf("4.Insert Node @ \n");
	     printf("5.Reverse List \n");
	     printf("6.Get length of List \n");
	     printf("7.Find the num in List \n");
	     printf("8.Delete Node @ \n");
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
		     case 6:
			     len = getListLength(mList);
			     printf("ListLength = %d\n",len);
			     break;
		     case 7:
			     printf("Enter the number to find in List\n");
			     scanf("%d",&num);
			     status = findNumList(mList,num);
			     (status)?printf("Num Found\n"):printf("Num Not found\n");
			     break;
		     case 8:
			     printf("Enter node position to delete\n");
			     scanf("%d",&nodePos);
			     mList = deleteNode(mList,nodePos);
			     break;
		     default:
			     printf("Invalid Option\n");
			     break;

			     
	     
	     }
     }
     

     return 0;
}
