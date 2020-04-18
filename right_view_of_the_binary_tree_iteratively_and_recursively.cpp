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
void rightViewOfTheTreeRecursively(node *root, int level, int &last_level)
{

    if (root == nullptr)
        return;

    if (last_level < level)
    {
        printf("%d ",root->key);
        last_level = level;
    }
    rightViewOfTheTreeRecursively(root->right, level + 1, last_level);
    rightViewOfTheTreeRecursively(root->left, level + 1, last_level);

}
void rightViewOfTheTreeIteratively(struct node * root){
    if(root == NULL){return;}
    enQueue(&start,&root);
    node * temp = NULL;
    while(!emptyqueue()){
        int count = lengthQueue();
        int i = 0;
        while(i++ < count){
            temp = peekqueue(&start);
            deQueue(&start);
            if(i ==  count)  printf("%d ",temp->key);
            if(temp->left) enQueue(&start,&temp->left);
            if(temp->right) enQueue(&start,&temp->right);
        }
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
    rightViewOfTheTreeIteratively(root);
    printf("\n");
    int last_level = 0;
    rightViewOfTheTreeRecursively(root, 1, last_level);
    return 0;
}
