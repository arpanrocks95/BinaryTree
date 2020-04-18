#include <stdio.h>
#include <malloc.h>
/* nodes for queue and tree node*/
struct node {
    int key;
    struct node * left = NULL;
    struct node * right = NULL;
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
    printf("%d is deleted \n",temp->point->key);
    free(temp);
}
struct node *  peek(struct qnode ** start){
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
int sizeOfQueue(struct qnode ** start){
    struct qnode * temp = *start;
    int count = 0;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count+1;
}

void iterativeHeight(struct node * root){
    int height = 0;
    struct node * temp = NULL;
    if(root == NULL){
        printf("height of the tree is %d",0);
    } else{
        enQueue(&start,&root);
        while(!empty()){
            int size  = sizeOfQueue(&start);

            while(size--){
                temp = peek(&start);
                deQueue(&start);

                if(temp->left) {enQueue(&start,&temp->left);}
                if(temp->right) {enQueue(&start,&temp->right);}

            }

            height++;

        }


    }
    printf("%d is the height of the tree  \n",height);

}


int main(){
    struct node * root  = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    iterativeHeight(root);

    return 0;
}


