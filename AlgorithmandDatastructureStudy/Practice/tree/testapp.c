#include <stdio.h>
#include "tree.h"




int main()
{
    int op = 0;
    int exit = 0;
    
    myTreeNode * myTree = NULL;

     while(!exit)
     {
     
	     printf("Enter the option\n");
	     printf("1.Craete Tree\n");
	     printf("2.Print Tree\n");
	     printf("3.Size of Tree\n");
	     printf("0.Exit\n");

	     scanf("%d",&op);
	     switch(op)
	     {
		     case 0:
			     exit = 1;
			     break;
		     case 1:
			     myTree = (myTreeNode*)createNewTreeNode(1);
			     myTree->left = (myTreeNode*)createNewTreeNode(2);
			     myTree->right = (myTreeNode*)createNewTreeNode(3);
			     myTree->left->left = (myTreeNode*)createNewTreeNode(4);
			     myTree->left->right = (myTreeNode*)createNewTreeNode(5);
			     myTree->right->left = (myTreeNode*)createNewTreeNode(6);
			     myTree->right->right = (myTreeNode*)createNewTreeNode(7);

			     break;
		     case 2:
			     printTree(myTree);
			     break;
		     case 3:
			     printf("Tree Size = %d\n",getTreeSize(myTree));
			     break;
		     case 4:
			     break;
		     case 5:
			     break;
		     case 6:
			     break;
		     case 7:
			     break;
		     case 8:
			     break;
		     default:
			     printf("Invalid Option\n");
			     break;

			     
	     
	     }
     }
     

     return 0;
}
