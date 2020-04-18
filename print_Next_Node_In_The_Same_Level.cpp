#include <stdio.h>
#include <malloc.h>

/* nodes  tree node*/
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


/*function for level order traversal next node iteratively*/

void printNextNodeInTheSameLevel(struct node * root,int key1){
    struct qnode *  start2 = NULL;
    struct node * temp = NULL;
    if(root == NULL){

    } else{
        enQueue(&start,&root);
        while(!emptyqueue()){
            int size  = lengthQueue();

            while(size--){
                temp = peekqueue(&start);
                enQueue(&start2,&temp);
                deQueue(&start);
                if(temp->left) {enQueue(&start,&temp->left);}
                if(temp->right) {enQueue(&start,&temp->right);}
            }

        }
    }
    struct qnode* iter= start2;
    while(iter != NULL){
        if (iter->point->key == key1){
            if(iter->next == NULL){
                printf("%s","null");
            } else{
                printf("%d",iter->next->point->key);
            }
        }
        iter=iter->next;
    }


}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);
    printNextNodeInTheSameLevel(root,7);

    return 0;
}
