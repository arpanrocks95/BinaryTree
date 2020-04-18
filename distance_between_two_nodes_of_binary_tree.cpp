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



// Function to find aall the paths from the root
int isNodePresent(node* root, node* node)
{

    if (root == NULL)
        return 0;

    if (root == node)
        return true;

    return isNodePresent(root->left, node) ||
           isNodePresent(root->right, node);
}


int findLCA1(node* root, node* &lca, node* x, node* y,int & distance )
{

    if (root == NULL)
        return 0;

    if (root == x || root == y)
    {
        lca = root;
        return 1;
    }

    bool left = findLCA1(root->left, lca, x, y,distance);

    bool right = findLCA1(root->right, lca, x, y,distance);

    if (left && right){
        lca = root;

    }

    if (left || right) distance++;

    return left || right;
}

int findLevel(struct node * root ,struct node * node,int level){
    if (root == NULL) return INT_MIN;
    if (root == node) return level;
    int left = findLevel(root->left,node,level+1);
    if(left !=  INT_MIN) return left;
    return findLevel(root->right,node,level+1);

}

// Function to find lowest common ancestor of nodes x and y
int findDistance(node* root, node* x, node* y)
{
    int distance = 0;
    struct node *lca = NULL;

    if (isNodePresent(root, y) && isNodePresent(root, x))
        findLCA1(root, lca, x, y,distance);

    return findLevel(lca, x, 0) + findLevel(lca, y, 0);
}


// main function
int main()
{
    struct node*     root = newNode(1);
    /* Construct below tree
          1
        /   \
       /     \
      2       3
       \     / \
        4   5   6
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

    printf("%d is ditance between %d and %d",findDistance(root,root->right->left->left, root->left->right),root->right->left->left->key,root->left->right->key);

    return 0;
}