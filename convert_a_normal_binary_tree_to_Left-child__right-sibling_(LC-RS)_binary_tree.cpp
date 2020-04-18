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


void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}



void convertToLeftChildBinaryTree(node* root)
{

    if (root == NULL )
        return ;
    convertToLeftChildBinaryTree(root->left);
    convertToLeftChildBinaryTree(root->right);
    if(root->left == NULL){
        root->left = root->right;
        root->right = NULL;
    }else{
        root->left->right = root->right;
        root->right = NULL;
    }
}


void convert(node* root)
{
    convertToLeftChildBinaryTree(root);
    preorder(root);
}

int main(){


    /* Construct below Tree
              1
            /  \
           /    \
          2      3
         / \    /
        4   5  6
              / \
             7   8
    */

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);
    convert(root);



    return 0;
}
