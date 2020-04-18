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
/* function for comparing two trees recurisvely */
int identicalBinaryTree(struct node * root1 , struct node * root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    if(root1 != NULL && root2 != NULL){
        return(
                root1->key == root2->key &&
                identicalBinaryTree(root1->left,root2->left) &&
                identicalBinaryTree(root1->right,root2->right)
                );
    }
    return 0; /* one empty one not */
}


int main(){
    struct node * root1  = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);

    struct node * root2  = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    root2->right->left = newNode(6);
    root2->right->right = newNode(7); /* rplace 7 by 17 and see the magic */

    if(identicalBinaryTree(root1,root2)){
        printf("%s","Yes Trees are identical");
    }else{
        printf("%s","No Trees are not identical");
    }
    return 0;
}
