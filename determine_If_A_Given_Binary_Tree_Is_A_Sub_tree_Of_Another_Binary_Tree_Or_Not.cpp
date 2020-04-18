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


/*fuction for converting a binary tree into sum tree*/
void preOrderTraversal(struct node * root,int & count,int array[]){
    if(root == NULL){
        return ;
    }
    array[count] = root->key;count++;
    preOrderTraversal(root->left,count,array);
    preOrderTraversal(root->right,count,array);
}

void postOrderTraversal(struct node * root,int & count,int array[]){
    if(root == NULL){
        return ;
    }
    postOrderTraversal(root->left,count,array);
    postOrderTraversal(root->right,count,array);
    array[count] = root->key;count++;
}


int determineIfAGivenBinaryTreeIsASubtreeOfAnotherBinaryTreeOrNot(struct node * root,struct node * subroot){
    if(root == subroot) return 1;
    if(root != NULL && subroot == NULL || root ==NULL && subroot != NULL) return 0;
    int prearrayroot [10];
    int postarrayroot [10];
    int presubarray[5];
    int postsubarray[5];
    int countroot = 0;
    int countsubroot = 0;
    int cond1 = 0;
    int cond2 = 0;
    preOrderTraversal(root,countroot,prearrayroot);
    preOrderTraversal(subroot,countsubroot,presubarray);
    countroot = 0;countsubroot=0;
    postOrderTraversal(root,countroot,postarrayroot);
    postOrderTraversal(subroot,countsubroot,postsubarray);
    for (int i = 0; i < countroot - countsubroot +1; ++i) {
        if (prearrayroot[i] == presubarray[0] && prearrayroot[i+1] == presubarray[1] && prearrayroot[i+2] == presubarray[2]) cond1 = 1;
        if ( postarrayroot[i] == postsubarray[0] && postarrayroot[i+1] == postsubarray[1] && postarrayroot[i+2] == postsubarray[2]) cond2 = 1;
    }
    if (cond1 == 1 && cond2 == 1)return 1;
    else return 0;
}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    struct node * root2 = newNode(10);
    root2->left = newNode(11);
    root2->right = newNode(12);


    /*replace root->right   by root2*/
    (determineIfAGivenBinaryTreeIsASubtreeOfAnotherBinaryTreeOrNot(root,root->right) == 1) ? printf("Yes\n") :printf("No\n");

    return 0;
}
