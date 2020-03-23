#include <stdio.h>
#include <malloc.h>
/* nodes for queue and tree node*/
struct node {
    int key;
    struct node * left;
    struct node * right;
};
struct qnode {
    struct node * point ;
    struct qnode * next ;
};

struct qnode * start = NULL;
/* function for creating new node of tree*/
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

/* function for enqueuing a tree node in queue*/
void enQueue(struct qnode ** start,struct node ** treenode){
    struct qnode * temp = *start;
    struct qnode *qnodetemp = (struct qnode *)malloc(sizeof(struct qnode));
    qnodetemp->point = *treenode;
    qnodetemp->next = NULL;
    if (*start == NULL){
        *start = qnodetemp;
    } else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = qnodetemp;
    }
    printf("%d inserted successfully \n",(*treenode)->key);
}
void deQueue(struct qnode ** start){
    struct qnode * temp = *start;
    *start = temp->next;
    free(temp);
}
void peek(struct qnode ** start){
    printf("%d is the data in front of the queue\n",(*start)->point->key);
}
int empty(){
    if (start == NULL){
        return  1;
    }
    else{
        return 0;
    }
}
int main(){
    struct node * one = newNode(10);
    struct node * two = newNode(11);
    struct node * three  = newNode(13);
    one->left = two;
    one->right = three;
    enQueue(&start,&one);
    enQueue(&start,&two);
    peek(&start);
    deQueue(&start);
    peek(&start);
    return 0;
}