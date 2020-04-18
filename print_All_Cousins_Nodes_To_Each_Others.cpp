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
void printAllCousinsNodesToEachOthers(struct node * root){

    struct node * temp = NULL;
    if(root == NULL){
        return ;
    } else{

        enQueue(&start,&root);

        while(!emptyqueue()){

            int size  = lengthQueue();
            int leftchild [2][20] = {0};
            int count =0;
            while(size--){
                temp = peekqueue(&start);
                deQueue(&start);
                if(temp->left){
                    leftchild[0][count] = temp->left->key;
                    leftchild[1][count] = temp->key;
                    count++;
                }
                if (temp->right){
                    leftchild[0][count] = temp->right->key;
                    leftchild[1][count] = temp->key;
                    count++;
                }

                if(temp->left) {enQueue(&start,&temp->left);}
                if(temp->right) {enQueue(&start,&temp->right);}
            }

            for (int i = 0; i < count ; ++i) {
                for (int j = 0; j < count ; ++j) {
                    if(leftchild[1][i] != leftchild[1][j]){
                        printf("(%d,%d)\n",leftchild[0][i],leftchild[0][j]);
                    }

                }
            }


        }



    }
}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);
    printAllCousinsNodesToEachOthers(root);


    return 0;
}
