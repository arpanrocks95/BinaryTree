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





/*function for level order traversal iteratively*/

void checkGivenTreeIsACompleteBinaryTreeOrNot(struct node * root){
    int condition = 1;
    struct node * temp = NULL;
    if(root == NULL){

    } else{
        enQueue(&start,&root);
        while(!emptyqueue()){
            int size  = lengthQueue();
            while(size--){
                temp = peekqueue(&start);
                if(temp->left == NULL && temp->right != NULL || temp->right == NULL && temp->left != NULL){condition = 0;}
                deQueue(&start);
                if(temp->left) {enQueue(&start,&temp->left);}
                if(temp->right) {enQueue(&start,&temp->right);}
            }

        }
    }
    if(condition){
        printf("%s\n","Given Binary Tree Is Complete Binary Tree");
    } else{
        printf("%s\n","Given Binary Tree Is Not A Complete Binary Tree");
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
    checkGivenTreeIsACompleteBinaryTreeOrNot(root);

    struct node *root1 = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    checkGivenTreeIsACompleteBinaryTreeOrNot(root1);

    return 0;
}
