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

    myList * curr = mList;
    myList * next = NULL;
    myList * prev = NULL;

    if(NULL == mList ) return NULL ;

    while(NULL != curr)
    {
        next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
    }
    mList = prev ;
    return mList;

/*
//recurrsive impl
    myList * first = NULL;
    myList * rest = NULL;

    PRINT("calling reverse\n");
    if(NULL == mList) return NULL;

    first = mList;
    rest = first->next;

    if(NULL == rest) return NULL;

    rest = reverseList(rest);

    first->next->next = first;
    first->next = NULL;

//    mList = rest;

    return rest;
*/

}

int getListLength(myList * mList)
{

	int len = 0;
        if(NULL == mList) return 0;
	while(mList)
	{
	    mList = mList->next;
	    len++;
	}

	return len;

	/*
        if(NULL == mList) 
	{
		return 0;
	}
	else
	{
	    return(1+getListLength(mList->next));
	}
	*/
}

bool findNumList(myList * mList,int num)
{
/*
     if(mList == NULL)
     {
          printf("Invalid List \n");
	  return false;
     }

     while(mList)
     {
         if(num == mList->val)
	 {
	     return true;
	 }
	 mList = mList->next;
     }
     return false;
 */
     if(mList == NULL)
     {
           return false;
     }
     if(num != mList->val)
     {
          findNumList(mList->next,num);
     }
     else
     {
          return true;
     }
     
}

myList * deleteNode(myList * mList,int nodePos)
{
	myList * head = mList;
	myList * temp = mList;
	myList * prev = NULL;
	int index = 0;
	if(NULL == mList) return NULL;
	
	while(temp  && index != nodePos)
	{
		PRINT("index %d\n",index);
		index++;
		prev = temp;
		temp = temp->next;
	}
	if(index == nodePos)
	{
		PRINT("free List[%d]:%d\n",index,temp->val);
		if(0 == nodePos)
		{
			head = temp->next;    
			free(temp);
		}
		else
		{
			prev->next = temp->next;
			free(temp);
		}
	}



	return head;
}
