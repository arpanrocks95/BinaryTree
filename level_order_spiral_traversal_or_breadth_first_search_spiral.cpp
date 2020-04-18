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


/*stack*/

struct snode {
    struct node * point ;
    struct snode * next ;
};

struct snode * top = NULL;


/* function for pushing,popping,peeking,to check that is stack is empty  a tree node in stack*/
void push(struct snode ** start, struct node ** treenode){
    struct snode *qnodetemp = (struct snode *)malloc(sizeof(struct snode));
    qnodetemp->point = *treenode;
    qnodetemp->next = (*start);
    (*start) = qnodetemp;


}
void pop(struct snode ** start){
    if((*start)->next != NULL)
        (*start) = (*start)->next;
    else(*start) = NULL;

}
struct  node * peekstack(struct snode ** start){
    return (*start)->point;
}
int emptystack(){
    if (top == NULL){
        return  1;
    }
    else{
        return 0;
    }
}
int lengthStack(){
    if(top == NULL){
        return 0;
    }
    int height = 0;
    struct snode* tempiter = top;
    while(tempiter != NULL){
        tempiter = tempiter->next;
        height++;
    }
    return height;
}

/*queue*/

struct qnode {
    struct node * point ;
    struct qnode * next ;
};

struct qnode * start = NULL;

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

}
void deQueue(struct qnode ** start){
    struct qnode * temp = *start;
    *start = temp->next;
    free(temp);
}
struct node * peekqueue(struct qnode ** start){
    return (*start)->point;
}
int emptyqueue(){
    if (start == NULL){
        return  1;
    }
    else{
        return 0;
    }
}
int lengthQueue(){
    if(start == NULL){
        return 0;
    }
    int height = 0;
    struct qnode* tempiter = start;
    while(tempiter != NULL){
        tempiter = tempiter->next;
        height++;
    }
    return height;
}


/*function for spiral level order */

void  SpiralLevelOrder(struct node * root){
    if(root == NULL){
        return ;
    }
    struct node * temp  = root;
    int height = 1;
    enQueue(&start,&temp);
    while(!emptyqueue() || !emptystack()){
        int count = 0;

        if(height%2 == 1){
            count = lengthQueue();
            while(count > 0){
                /*printf("%s","inside odd if\n");*/
                temp = peekqueue(&start);
                deQueue(&start);
                printf("%d ",temp->key);
                if(temp->left) enQueue(&start,&temp->left);
                if(temp->right) enQueue(&start,&temp->right);
                if(temp->right) push(&top,&temp->right);
                if(temp->left) push(&top,&temp->left);
                count--;
            }
            height++;

        } else{
            count = lengthStack();

            while(count--){
                struct node * temps = peekstack(&top);
                pop(&top);
                temp = peekqueue(&start);
                deQueue(&start);
                printf("%d ",temp->key);
                if(temps->left) enQueue(&start,&temps->left);
                if(temps->right) enQueue(&start,&temps->right);

            }        height++;
        }


    }

}


int main(){
    struct node *root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);
    iterativeHeight(root);
    SpiralLevelOrder(root);



    return 0;
}
