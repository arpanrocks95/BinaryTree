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



void inOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }
    inOrderTraversal(root->left);
    printf("%d ",root->key);
    inOrderTraversal(root->right);
}




struct node * convert(struct node * root){
    if(root == NULL){
        return NULL;
    }

    root->left = convert(root->left);
    root->right = convert(root->right);

    if((root->left && root->right) || (root->left == NULL && root->right == NULL)) return root;
    else {
        struct node * child ;
        child = (root->left)? root->left: root->right;
        delete root;
        return child;
    }
}

void convertHalfBinaryTreeIntoFull(struct node * root){

    convert(root);
    inOrderTraversal(root);
}


// main function
int main()
{


    /* Construct below tree
                 0
               /   \
              /     \
             1       2
            /       /
           /       /
          3       4
         /       / \
        /       /   \
       5       6     7
    */

    struct node * root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->right->left = newNode(4);
    root->left->left->left = newNode(5);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);


    convertHalfBinaryTreeIntoFull(root);

    return 0;
}
