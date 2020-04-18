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






void sendZeroNodesToBottom(struct node * root){
    if(root == NULL){
        return ;
    }

    sendZeroNodesToBottom(root->left);
    if(root->key == 0)  if(root->left && root->left->key != 0) {root->key = root->left->key;root->left->key = 0;}
    if(root->key == 0)  if(root->right && root->right->key != 0){root->key = root->right->key;root->right->key = 0;}
    sendZeroNodesToBottom(root->right);

}

void inOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }

    inOrderTraversal(root->left);
    printf("%d ",root->key);
    inOrderTraversal(root->right);
}

void sinkNodes(struct node * root,int n){
    for (int i = 0; i < n; ++i) {
        sendZeroNodesToBottom(root);
    }

    inOrderTraversal(root);
}


// main function
int main()
{
    /* Construct below tree
              0
            /   \
           /	 \
          1	   0
                /   \
               /	 \
              0	   2
            /   \
           /	 \
          3	   4
    */

    node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(0);
    root->right->left = newNode(0);
    root->right->right = newNode(2);
    root->right->left->left = newNode(3);
    root->right->left->right = newNode(4);

    sinkNodes(root,2);


    return 0;
}
