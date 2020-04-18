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

int recursiveHeight(struct node * root){
    if (root == NULL){
        return 0;
    } else{
        int lheight = recursiveHeight(root->left);
        int rheight = recursiveHeight(root->right);
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }

}

int main(){
    struct node * root  = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    int height = recursiveHeight(root);
    printf("%d is the height of the binary tree",height);
    return 0;
}
