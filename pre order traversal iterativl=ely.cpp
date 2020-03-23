#include <stdio.h>
#include <malloc.h>
/* nodes for queue and tree node*/
struct node {
    int key;
    struct node * left;
    struct node * right;
};
struct snode {
    struct node * point ;
    struct snode * next ;
};

struct snode * start = NULL;
/* function for creating new node of tree*/
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

/* function for pushing,popping,peeking,to check that is stack is empty  a tree node in stack*/
void push(struct snode ** start, struct node ** treenode){
    struct snode *qnodetemp = (struct snode *)malloc(sizeof(struct snode));
    qnodetemp->point = *treenode;
    qnodetemp->next = (*start);
    (*start) = qnodetemp;

}
struct node * pop(struct snode ** start){
    struct node * temp = (*start)->point;
    if((*start)->next != NULL){
        (*start) = (*start)->next;
    }
    else(*start) = NULL;
    return temp;

}
struct  node * peek(struct snode ** start){
    return (*start)->point;
}
int empty(){
    if (top == NULL){
        return  1;
    }
    else{
        return 0;
    }
}


/*function for Inorder Traversal  iteratively*/

void  PreorderIteratively(struct node * root){
    if(root == NULL){
        return ;
    }
    struct node * temp  = root;
    push(&top, &temp);
    while (!empty() ){
        if(temp != NULL){
            printf("%d",temp->key);
            if(temp->right != NULL) push(&top, &temp->right);
            temp = temp->left;
        } else{
            temp = pop(&top);

        }
    }

}


int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);
    PreorderIteratively(root);


    return 0;
}
