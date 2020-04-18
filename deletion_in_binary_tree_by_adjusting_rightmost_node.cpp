#include <stdio.h>
#include <malloc.h>
/*  tree node*/
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
/* function for traversing in inorder tree traversal */
void inOrderTraversal(struct node * root){
    if(root == NULL){
        return ;
    }
    inOrderTraversal(root->left);
    printf("%d ",root->key);
    inOrderTraversal(root->right);
}
struct node * temp5 ;
void preOrderTraversal(struct node * root,struct node * child){
    if(root == NULL){
        return ;
    }
    if (root->left == child ){

        temp5 = root;
        return;
    }
    if(root->right == child){

        temp5 = root;
        return;
    }
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}


struct node * tempforsearch ;
void search(struct node* node,
            int val)
{
    if (node == NULL)
        return ;

    if (node->key == val) {
        tempforsearch  = node;
    }
    else {
        search(node->left, val);
        search(node->right, val);
    }
}

/*function to find parent of a node in binary tree */

node * findParent(struct node* node,
                  int val, struct node * parent)
{
    if (node == NULL)
        return NULL;

    if (node->key == val) {
        return parent;
    }
    else {

        findParent(node->left, val, node);
        findParent(node->right, val, node);
    }
}

/* function for traversing in order level tree traversal */
int height(struct node * root){
    if (root == NULL){
        return 0;
    } else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }

}

node * printnodesatheight(struct node * root,int level,int right){
    if (root == NULL)
        return NULL;
    if (level == 1){
        if (right == 1){
            return root;
        }
    }
    else if (level > 1)
    {
        printnodesatheight(root->left, level-1,0);
        printnodesatheight(root->right, level-1,1);
    }
}

node * breadthFirstSearch(struct node * root){
    struct node * rightmostnode;
    int h = height(root);
    rightmostnode =    printnodesatheight(root,h,-1 );
    return rightmostnode;
}


/* function for deleting a node from the tree */
void deleteANodeFromBinaryTree(int key,struct node * root){
    search(root, key);
    struct  node * deletionNode = tempforsearch;

    struct node * rightmost  = breadthFirstSearch(root);
    struct node * parentofrightmost = findParent(root,rightmost->key,NULL);
    parentofrightmost->right = NULL;

    rightmost->left = deletionNode->left;
    rightmost->right = deletionNode->right;

    preOrderTraversal(root,deletionNode);
    struct node * parentofdeletion  = temp5;


    if(parentofdeletion->left == deletionNode){

        parentofdeletion->left = rightmost;
    }else{

        parentofdeletion->right = rightmost;
    }

}


int main(){
    struct node * root  = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);


    printf("%s","Inorder traversal of the tree is \n");
    inOrderTraversal(root);printf("\n");

    int key = 11;
    deleteANodeFromBinaryTree(key,root);

    printf("%s","Inorder traversal of the tree is \n");
    inOrderTraversal(root);printf("\n");
    return 0;
}


