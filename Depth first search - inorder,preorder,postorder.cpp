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
/* function for traversing in inorder,postorder,preorder tree traversal */
void inOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }
    inOrderTraversal(root->left);
    printf("%d ",root->key);
    inOrderTraversal(root->right);
}

void preOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }
    printf("%d ",root->key);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ",root->key);
}

int main(){
    struct node * root  = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("%s","Inorder traversal of the tree is \n");
    inOrderTraversal(root);printf("\n");
    printf("%s","preorder traversal of the tree is \n");
    preOrderTraversal(root);printf("\n");
    printf("%s","postorder traversal of the tree is \n");
    postOrderTraversal(root);printf("\n");
    return 0;
}