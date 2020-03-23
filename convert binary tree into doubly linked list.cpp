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



/*linekdlist doubly*/

struct linkedList {
    int data ;
    struct linkedList * prev ;
    struct linkedList * next ;
};

struct linkedList * start = NULL;

void insert(linkedList **start , int data){
    struct linkedList * temp = (struct linkedList *) malloc(sizeof(struct linkedList ));
    temp->data = data;
    if(*start == NULL){
        temp->prev = *start;
        temp->next = NULL;
        *start = temp;
        return;
    }
    else{
        struct linkedList * iter = *start;
        while(iter->next != NULL){
            iter = iter->next;
        }
        iter->next = temp;
        temp->prev = iter;
        temp->next = NULL;

    }
}


void inOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }
    inOrderTraversal(root->left);
    insert(&start,root->key);
    inOrderTraversal(root->right);
}


void convert(struct node * root){
    inOrderTraversal(root);
    struct  linkedList * iter =  start;
    while(iter != NULL){
        if(iter->next != NULL) printf("%d->",iter->data);
        else printf("%d",iter->data);
        iter = iter->next;
    }
}


int main(){
    /* Construct below tree
			  1
			/   \
		   /     \
		  2       3
		 / \     / \
		4   5   6   7
    */

    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    convert(root);

    return 0;

}
