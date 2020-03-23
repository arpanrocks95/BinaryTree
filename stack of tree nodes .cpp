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
    printf("%d inserted successfully \n",(*treenode)->key);
}
void pop(struct snode ** start){
    if((*start)->next != NULL)
        (*start) = (*start)->next;
    else(*start) = NULL;
    printf("%s\n"," popped successfully ");
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



int main(){
    node * node1 = newNode(1);
    node * node2  = newNode(2);
    node * node3  = newNode(3);
    push(&top, &node1);
    printf("%d\n",peek(&top)->key);
    push(&top, &node2);
    printf("%d\n",peek(&top)->key);
    pop(&top);
    printf("%d\n",peek(&top)->key);
    push(&top, &node3);
    printf("%d\n",peek(&top)->key);
    printf("%d empties result\n",empty());
    pop(&top);
    pop(&top);
    printf("%d empties result\n",empty());


    return 0;
}
