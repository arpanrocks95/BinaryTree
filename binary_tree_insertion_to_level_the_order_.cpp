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
void peek(struct qnode ** start){
    printf("%d is the data in front of the queue\n",(*start)->point->key);
}
int empty(){
    if (start == NULL){
        return  1;
    }
    else{
        return 0;
    }
}

/* inorder traversal function */
void inOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }
    inOrderTraversal(root->left);
    printf("%d ",root->key);
    inOrderTraversal(root->right);
}

/*function for inserting a key in level order*/
void insertToLevel(struct node * root,int key){
    enQueue(&start,&root);
    while(!empty()){
        struct  node * temp  = start->point;
        deQueue(&start);

        if(!temp->left){
            temp->left = newNode(key);
            break;
        } else{
            enQueue(&start,&temp->left);
        }
        if(!temp->right){
            temp->right  = newNode(key);
            break;
        } else{
            enQueue(&start,&temp->right);
        }
    }

}
int main(){
    struct node * root  = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    printf("%s","inorder traversal before insertion of the new node is : ");
    inOrderTraversal(root);
    printf("\n");
    int key = 12;
    insertToLevel(root, key);
    printf("%s","inorder traversal after insertion of the new node is : ");
    inOrderTraversal(root);
    return 0;
}