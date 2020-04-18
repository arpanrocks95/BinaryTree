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

/*function for deleting every node of the tree recursivelu*/

struct node *  deleteBinaryTreeIteratively(struct node * root){
    if(root == NULL){
        return NULL;
    }
    deleteBinaryTreeIteratively(root->left);
    deleteBinaryTreeIteratively(root->right);
    printf("%d ",root->key);
    free(root);
    return NULL;
}

int main(){
    struct node * root1  = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
    root1 = deleteBinaryTreeIteratively(root1);
    if(root1 == NULL){
        printf("%s","successfully deleted ");
    }
    return 0;
}
