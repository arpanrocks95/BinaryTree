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



/*fuction for converting a binary tree into sum tree*/

int isSumTree(struct node * root){
    if(root == NULL){
        return 0 ;
    }
    if(root->left == NULL && root->right == NULL)return root->key;

    if(root->key ==  + isSumTree(root->left) + isSumTree(root->right)) return 2*root->key;
    return INT_MIN;
}

int main(){
    struct node *root = newNode(44);
    root->left = newNode(9);
    root->right = newNode(13);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);


    if (isSumTree(root) != INT_MIN ){printf("this is a sum tree");}
    else{printf("this is not a sum tree");}
    return 0;
}
