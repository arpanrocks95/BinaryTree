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
void checkIfGivenTwiNodesAreCousinsToEachOthers(struct node * root, int a, int b){

    struct node * temp = NULL;
    if(root == NULL){
        return ;
    } else{
        int levelofA = NULL;
        int levelofB = NULL;
        int parentofA = NULL;
        int parentofB = NULL;
        int height = 1;
        enQueue(&start,&root);
        while(!emptyqueue()){
            int size  = lengthQueue();
            while(size--){
                temp = peekqueue(&start);
                deQueue(&start);
                if(temp->left){
                    if (temp->left->key == a){
                        levelofA = height;
                        parentofA = temp->key;
                    }
                    if (temp->left->key == b){
                        levelofB = height;
                        parentofB = temp->key;
                    }

                }
                if (temp->right){
                    if (temp->right->key == a){
                        levelofA = height;
                        parentofA = temp->key;
                    }

                    if (temp->right->key == b){
                        levelofB = height;
                        parentofB = temp->key;
                    }
                }

                if(temp->left) {enQueue(&start,&temp->left);}
                if(temp->right) {enQueue(&start,&temp->right);}
            } height++;


        }
        printf("%d is level of a %d is levele of b %d is parent of a and %d is parent of b \n",levelofA,levelofB,parentofA,parentofB);
        if( levelofA == levelofB && parentofA != parentofB){
            printf("%s\n"," The Given Keys Are Cousins");
        } else{
            printf("%s\n"," No The Given Keys Are Not Cousins");
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
    checkIfGivenTwiNodesAreCousinsToEachOthers(root, 2, 3);
    checkIfGivenTwiNodesAreCousinsToEachOthers(root, 4, 5);
    checkIfGivenTwiNodesAreCousinsToEachOthers(root, 4, 6);

    return 0;
}
