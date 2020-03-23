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


/*function to find parent of a node in binary tree */


void findParent(struct node* node,
                int val, struct node * parent)
{
    if (node == NULL)
        return;

    if (node->key == val) {

        printf("%d",parent->key);
    }
    else {

        findParent(node->left, val, node);
        findParent(node->right, val, node);
    }
}
// Driver code
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int node1 = 3;
    findParent(root, node1, NULL);
    return 0;
}