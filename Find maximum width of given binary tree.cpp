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

void LevelOrderTraversalModifiedForMaxWidth(struct  node *root,int &count){
    if (root == NULL) return;
    enQueue(&start,&root);
    while (!emptyqueue()){
        int count1 = lengthQueue();
        if(count1 > count ) count = count1;
        while(count1--){
            struct node * temp = peekqueue(&start);
            deQueue(&start);
            if(temp->left) enQueue(&start,&temp->left);
            if(temp->right) enQueue(&start,&temp->right);
        }
    }
}


void maxWidth(node* root)
{
    int count = 0;
    LevelOrderTraversalModifiedForMaxWidth(root,count);
    printf("%d is the max width of the binary tree",count);
}

int main(){
/* Construct below tree
			  8
			/   \
		   /	 \
		  3	      5
		 / \	 / \
		/   \   /   \
	   10	2  4	 6   */

    node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(10);
    root->left->right = newNode(2);
    root->right->left = newNode(4);
    root->right->right = newNode(6);

    maxWidth(root);

    return 0;
}
