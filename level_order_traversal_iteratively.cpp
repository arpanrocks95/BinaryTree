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
void levelOrderTraversalIteratively(struct node * root){

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
                printf("%d ",temp->key);
                if(temp->left) {enQueue(&start,&temp->left);}
                if(temp->right) {enQueue(&start,&temp->right);}
            }

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
    levelOrderTraversalIteratively(root);



    return 0;
}
