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
struct  node * peek(struct qnode ** start){
    return (*start)->point;
}
int empty(){
    if (start == NULL){
        return  1;
    }
    else{
        return 0;
    }
}

/*function for deleting every node of the tree iteratively*/

struct node *  deleteBinaryTreeIteratively(struct node * root){
    if(root == NULL){
        return NULL;
    }
    struct node * temp ;
    enQueue(&start,&root);
    while (!empty()){
        temp = peek(&start);
        deQueue(&start);
        if(temp->left){enQueue(&start,&temp->left);}
        if(temp->right){enQueue(&start,&temp->right);}
        delete temp;
    }

    return  NULL;
}

int main(){
    struct node * root1  = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
    root1 = deleteBinaryTreeIteratively(root1);
    if(root1 == NULL){
        printf("%s","successfully deleted ");
    }
    return 0;
}
