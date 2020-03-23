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

int equalafterswapsofnnumber(struct node * x,node * y){
    if(x == NULL && y== NULL) return 1;
    return (x && y) && (x->key == y->key) &&
           ((equalafterswapsofnnumber(x->left, y->left) && equalafterswapsofnnumber(x->right, y->right)) ||
            (equalafterswapsofnnumber(x->right, y->left) && equalafterswapsofnnumber(x->left, y->right)));

}

int main(){
    // construct first tree
    node* X = newNode(6);
    X->left = newNode(3);
    X->right = newNode(8);
    X->left->left = newNode(1);
    X->left->right = newNode(7);
    X->right->left = newNode(4);
    X->right->right = newNode(2);
    X->right->left->left = newNode(1);
    X->right->left->right = newNode(7);
    X->right->right->right = newNode(3);

    // construct second tree
    node* Y = newNode(6);
    Y->left = newNode(8);
    Y->right = newNode(3);
    Y->left->left = newNode(2);
    Y->left->right = newNode(4);
    Y->right->left = newNode(7);
    Y->right->right = newNode(1);
    Y->left->left->left = newNode(3);
    Y->left->right->left = newNode(1);
    Y->left->right->right = newNode(7);

    if(equalafterswapsofnnumber(X,Y)) printf("yes");
    else printf("no");
    return 0;
}
