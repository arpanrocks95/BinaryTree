#include <stdio.h>
#include <malloc.h>
#include <limits.h>

/* nodes for queue and tree node*/
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


/* function to determine the diameter of a binary tree */

int isSymmetrical(struct node * x, struct node * y){
    if(x == NULL && y == NULL)return 1;

    return (x != NULL && y != NULL) &&
           isSymmetrical(x->left, y->right) &&
           isSymmetrical(x->right, y->left);
}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    if(isSymmetrical(root->left,root->right)) printf("YES");
    else printf("NO");

    return 0;
}
