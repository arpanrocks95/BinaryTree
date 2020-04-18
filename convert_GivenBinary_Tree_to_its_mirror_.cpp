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

void preOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }
    printf("%d ",root->key);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

/* function to determine the diameter of a binary tree */

int mirrorGivenBinaryTree(struct node * root){
    if(root  == NULL) return 1;
    mirrorGivenBinaryTree(root->left);
    mirrorGivenBinaryTree(root->right);
    struct node * temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main(){
    struct node* root = NULL;
    /* Construct below tree
          1
        /   \
       /     \
      2       3
     / \     / \
    4   5   6   7   */

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    mirrorGivenBinaryTree(root);
    preOrderTraversal(root);
    return 0;
}
