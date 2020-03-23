#include <stdio.h>
#include <malloc.h>
#include <limits.h>

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

// Function to find aall the paths from the root

void ancestorOfANodeUsingArray(node * root, int *array, int & count,int data){
    if(root == NULL) return;
    array[count++] = root->key;
    if(root->key == data){
        for (int i = 0; i < count -1; ++i)
            if(i+2 != count) printf("%d->",array[i]);
            else printf("%d",array[i]);
        printf("\n");
    }
    ancestorOfANodeUsingArray(root->left, array, count,data);
    ancestorOfANodeUsingArray(root->right, array, count,data);
    count--;
}
int ancestorOfANodeUsingRecursionWithoutExtraaSpace(node * root,int data){
    if (root == NULL) return 0;
    if (root->key == data) return 1;
    int left = ancestorOfANodeUsingRecursionWithoutExtraaSpace(root->left ,data);
    int right = 0;
    if (!left) right = ancestorOfANodeUsingRecursionWithoutExtraaSpace(root->right,data);
    if (left || right) printf("%d ",root->key);
    return left || right;
}
void ancestorOfANodeUsingiTerativeMethod(node * root,int data){
    struct node * temp = NULL;
    if(root == NULL){
        printf("height of the tree is %d",0);
        return;
    } else{
        enQueue(&start,&root);
        while(!emptyqueue()){
            int size  = lengthQueue();

            while(size--){
                temp = peekqueue(&start);
                deQueue(&start);
                push(&top,&temp);
                if(temp->left == NULL && temp->right == NULL) pop(&top);
                if(temp->left) {enQueue(&start,&temp->left);}
                if(temp->right) {enQueue(&start,&temp->right);}
            }

        }
    }
    while (!emptystack()){
        node * temp  = peekstack(&top);
        pop(&top);
        if(temp->left)  if(temp->left->key == data) {printf("%d ", temp->key);data = temp->key;}
        if(temp->right) if(temp->right->key ==  data) {printf("%d ", temp->key);data = temp->key;}
    }



}
void findAncestors(node* root,int data)
{
    int array[10];
    int count = 0;
    ancestorOfANodeUsingArray(root, array, count,data);
    ancestorOfANodeUsingRecursionWithoutExtraaSpace(root,data);
    printf("\n");
    ancestorOfANodeUsingiTerativeMethod(root,data);
}


int main(){
    node* root =   root = newNode(1);

    /* Construct below tree
         1
       /   \
      /     \
     2      3
      \    / \
       4  5   6
         / \
        7   8
    */


    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->right->right = newNode(8);


    // print all root to leaf paths
    findAncestors(root, 7);

    return 0;
}
