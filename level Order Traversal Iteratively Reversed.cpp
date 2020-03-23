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


/*function for level order traversal iteratively*/
void levelOrderTraversalIterativelyReversed(struct node * root){

    struct node * temp = NULL;
    if(root == NULL){
        printf("height of the tree is %d",0);
    } else{
        enQueue(&start,&root);
        while(!emptyqueue()){
            int size  = lengthQueue();
            while(size--){
                temp = peekqueue(&start);
                deQueue(&start);
                push(&top,&temp);
                if(temp->right) {enQueue(&start,&temp->right);}
                if(temp->left) {enQueue(&start,&temp->left);}
            }
        }
        while(!emptystack()){
            printf("%d ",peekstack(&top)->key);
            pop(&top);
        }

    }


}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    levelOrderTraversalIterativelyReversed(root);



    return 0;
}
