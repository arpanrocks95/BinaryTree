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





void printCornerNodes(struct node * root){
    enQueue(&start,&root);
    while(!emptyqueue()){
        int count = lengthQueue();
        if(peekqueue(&start) != root)printf("%d ",peekqueue(&start)->key);
        while(count--){
            struct node * temp = peekqueue(&start);
            if( count == 0) printf("%d ",temp->key);
            deQueue(&start);
            if(temp->left) enQueue(&start,&temp->left);
            if(temp->right) enQueue(&start,&temp->right);
        }
        printf("\n");
    }
}



int main(){
    /* Construct below tree
				 1
				/ \
			   /   \
			  2     3
			 /     / \
			/     /   \
		   4     5     6
		  /     / \     \
		 /     /   \     \
		7     8     9     10
    */

    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->right->left->left = newNode(8);
    root->right->left->right = newNode(9);
    root->right->right->right = newNode(10);
    printCornerNodes(root);


    return 0;
}
