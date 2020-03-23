#include <stdio.h>
#include <malloc.h>
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

int convertGivenBinaryTreeIntoSumTree(struct node * root){
    if(root == NULL){
        return 0;
    }
    int left = 0;int right=0;
    left = convertGivenBinaryTreeIntoSumTree(root->left);
    right = convertGivenBinaryTreeIntoSumTree(root->right);
    int old = root->key;
    root->key = left + right;
    return old+root->key;
}
void preOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }
    printf("%d ",root->key);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
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
    convertGivenBinaryTreeIntoSumTree(root);
    preOrderTraversal(root);
    return 0;
}
