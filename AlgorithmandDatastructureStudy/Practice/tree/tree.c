#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define PRINT printf

myTreeNode * createNewTreeNode(int data)
{
     myTreeNode * treeNode = NULL;

     treeNode = (myTreeNode *)malloc(sizeof(myTreeNode));
     treeNode->val = data;
     treeNode->left = NULL;
     treeNode->right = NULL;

     return treeNode;
}
void printTree(myTreeNode * myTree)
{
     printf("In-Order\n");
     printInOrderTree(myTree);
     printf("\n");
     printf("Pre-Order\n");
     printPreOrderTree(myTree);
     printf("\n");
     printf("Post-Order\n");
     printPostOrderTree(myTree);
     printf("\n");

     return;
}
void printInOrderTree(myTreeNode * myTree)
{
     if (NULL == myTree) return;
     printInOrderTree(myTree->left);
     printf("%d ",myTree->val);
     printInOrderTree(myTree->right);
     return;
}
void printPreOrderTree(myTreeNode * myTree)
{
     if (NULL == myTree) return;
     printf("%d ",myTree->val);
     printPreOrderTree(myTree->left);
     printPreOrderTree(myTree->right);
     return;
}
void printPostOrderTree(myTreeNode * myTree)
{
     if (NULL == myTree) return;
     printPostOrderTree(myTree->left);
     printPostOrderTree(myTree->right);
     printf("%d ",myTree->val);
     return;
}
int getTreeSize(myTreeNode * myTree)
{

    if(NULL == myTree) return 0;

    return 1 + getTreeSize(myTree->left) + getTreeSize(myTree->right);

}
int getTreeHeight(myTreeNode * myTree)
{
     int lHeight = 0;
     int rHeight = 0;
     if(NULL == myTree) return 0;
     
     lHeight = getTreeHeight(myTree->left);
     rHeight = getTreeHeight(myTree->right);

     return (lHeight > rHeight)?lHeight+1 : rHeight+1;
}
