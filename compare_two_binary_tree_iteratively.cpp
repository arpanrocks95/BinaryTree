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
/*  queue  node*/
struct qnode {
    struct node * point ;
    struct qnode * next ;
};

struct qnode * start1 = NULL;
struct qnode * start2 = NULL;

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
struct node * peek(struct qnode ** start){
    return (*start)->point;
}
int sizeOfQueue(struct qnode ** start){
    struct qnode * temp = *start;
    int count = 0;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count+1;
}

int empty(struct qnode * start){
    if (start == NULL){
        return  1;
    }
    else{
        return 0;
    }
}


/* function for comparing two trees iteratively */
int identicalBinaryTree(struct node * root1 , struct node * root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    if(root1 != NULL && root2 != NULL){

        int count1 = 0;
        int count2 = 0;
        struct node * temp1 = NULL;
        struct node * temp2 = NULL;
        enQueue(&start1,&root1);enQueue(&start2,&root2);
        while(!empty(start1) && !empty(start2)){
            count1 = sizeOfQueue(&start1);
            count2 = sizeOfQueue(&start2);
            if(count1 != count2){
                return 0;
            }
            while(count1--){
                temp1 = peek(&start1);temp2 = peek(&start2);
                deQueue(&start1);deQueue(&start2);
                if(temp1->key != temp2->key){return 0;}
                if(temp1->left){enQueue(&start1,&temp1->left);}
                if(temp1->right){enQueue(&start1,&temp1->right);}
                if(temp2->left){enQueue(&start2,&temp2->left);}
                if(temp2->right){enQueue(&start2,&temp2->right);}
            }

        }
        return 1;
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
    root2->right->right = newNode(17); /* rplace 7 by 17 and see the magic */

    if(identicalBinaryTree(root1,root2)){
        printf("%s","Yes Trees are identical");
    }else{
        printf("%s","No Trees are not identical");
    }
    return 0;
}
