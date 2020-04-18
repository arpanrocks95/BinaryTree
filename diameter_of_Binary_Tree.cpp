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

int diameterofBinaryTree(struct node * root,int & diameter){
    if(root == NULL)return 0;

    int left = diameterofBinaryTree(root->left,diameter);
    int right = diameterofBinaryTree(root->right,diameter);

    int max_diameter = left + right +1;
    if (diameter < max_diameter) diameter = max_diameter;

    if (left > right) return left + 1;
    else return right +1;
}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);

    int diameter = 0;
    diameterofBinaryTree(root,diameter);
    printf("%d is the diameter of the tree",diameter);

    return 0;
}
