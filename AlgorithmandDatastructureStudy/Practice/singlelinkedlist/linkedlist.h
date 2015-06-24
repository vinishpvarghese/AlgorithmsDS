#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include<stdbool.h>

typedef struct __myList{

        int val;
	struct __myList * next;

}myList;


myList * createList(int num);
void printList(myList * mList);
void insertVal(myList * mList,int nodeVal);
myList * insertValAt(myList * mList,int nodeVal,int nodePos);
myList * reverseList(myList * mList);
int getListLength(myList * mList);
bool findNumList(myList * mList,int num);
myList * deleteNode(myList * mList,int nodePos);



#endif /*__LINLKEDLIST_H*/
