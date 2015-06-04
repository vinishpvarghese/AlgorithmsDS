#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define PRINT printf

myList * createList(int numNodes)
{
	myList * head = NULL;
	myList * node = NULL;
	myList * prevNode = NULL;
	int index = 0;
	int nodeVal = 0;

	while(index < numNodes)
	{
		printf("Enter the Node Value\n");
		scanf("%d",&nodeVal);

		node = (myList *)malloc(sizeof(myList));
		node->val = nodeVal ;
		node->next = NULL;

		if(0 == index)
		{
			head = node;
		}

		if(prevNode)
		{
			prevNode->next = node ;
		}

		prevNode = node;
		index++;

	}

	return head;
}

void printList(myList * mList)
{
    int index = 0;
    if(NULL == mList) return;
    
    while(mList)
    {
           printf("mList[%d] = %d\n",index,mList->val);
	   mList = mList->next;
	   index++;
    }    
    return;
}

void insertVal(myList * mList,int nodeVal)
{
    myList * node = NULL;
    myList * head = mList;
    int index = 0;

    if(NULL == mList) return;


    node = (myList *)malloc(sizeof(myList));
    node->val = nodeVal ;
    node->next = NULL;

    while(mList->next)
    {
        mList = mList->next;
	index++;
    }
    mList->next = node;
    printf("inserted the node @ %d\n",index);
    
    mList = head;

    return;
}
myList * insertValAt(myList * mList,int nodeVal,int nodePos)
{

    myList * node = NULL;
    myList * head = mList;
    int index = 0;

    if(NULL == mList) return NULL;

    
    node = (myList *)malloc(sizeof(myList));
    node->val = nodeVal ;
    node->next = NULL;
    
    if(nodePos == 0)
    {       
	    node->next = head;
	    head = node;
	    PRINT("inserted @ index = %d\n",index);
	    index++;
    }
    else
    {
	    while(mList)
	    {
		    if((index +1) == nodePos)
		    {
			    node->next = mList->next;
			    mList->next = node;
			    PRINT("inserted @ index = %d\n",index+1);
			    index++;
			    break;
		    }
		    mList = mList->next;
		    index++;
	    }
    }
    
    return head;
}

myList * reverseList(myList * mList)
{


    return mList;

}


