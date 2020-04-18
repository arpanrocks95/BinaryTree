#include <stdio.h>
#include <malloc.h>
/*  tree node*/
struct node {
    int key;
    struct node * left;
    struct node * right;
};

/* function for creating new node of tree*/
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
/* function for traversing in level order that is breadth first search */

int height(struct node * root){
    if (root == NULL){
        return 0;
    } else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }

}

void printnodesatheight(struct node * root,int level){
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ",root->key);
    else if (level > 1)
    {
        printnodesatheight(root->left, level-1);
        printnodesatheight(root->right, level-1);
    }
}

void breadthFirstSearch(struct node * root){
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printnodesatheight(root, i);
}

int main(){
    struct node * root  = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("%s","level order  traversal of the tree is \n");
    breadthFirstSearch(root);
    return 0;
}