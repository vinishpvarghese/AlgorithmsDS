#ifndef __TREE_H
#define __TREE_H

#include<stdbool.h>

typedef struct __myTreeNode{

        int val;
	struct __myTreeNode * left;
	struct __myTreeNode * right;

}myTreeNode;


myTreeNode * createNewTreeNode(int);
void printTree(myTreeNode *);
void printInOrderTree(myTreeNode *);
void printPreOrderTree(myTreeNode *);
void printPostOrderTree(myTreeNode *);
int getTreeSize(myTreeNode *);
int getTreeHeight(myTreeNode *);


#endif /*__LINLKEDLIST_H*/
