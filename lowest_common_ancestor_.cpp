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


int findLCA(node* root, node* &lca, node* x, node* y)
{

    if (root == NULL)
        return 0;

    if (root == x || root == y)
    {
        lca = root;
        return 1;
    }

    bool left = findLCA(root->left, lca, x, y);

    bool right = findLCA(root->right, lca, x, y);

    if (left && right)
        lca = root;

    return left || right;
}

// Function to find lowest common ancestor of nodes x and y
void findLCA(node* root, node* x, node* y)
{

    node *lca = NULL;

    if (isNodePresent(root, y) && isNodePresent(root, x))
        findLCA(root, lca, x, y);

    if (lca != NULL)
        printf("LCA is %d \n",lca->key);
    else
        printf("LCA do not exist\n");
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

    findDistance(root, root->right->left->left, root->right->right);
    findDistance(root, root->right->left->left, newNode(10));
    findDistance(root, root->right->left->left, root->right->left->left);
    findDistance(root, root->right->left->left, root->right->left);
    findDistance(root, root->left, root->right->left);

    return 0;
}