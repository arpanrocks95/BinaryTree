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


void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

bool isLeaf(node* node)
{
    return (node->left == NULL && node->right == NULL);
}


void trunc(node* &curr, int k, int sum)
{

    if (curr == NULL)
        return;

    sum = sum + (curr->key);

    trunc(curr->left, k, sum);
    trunc(curr->right, k, sum);

    if(sum < k && isLeaf(curr))
    {

        delete(curr);
        curr = NULL;
    }
}


void truncate(node* &root, int k)
{
    int sum = 0;
    trunc(root, k, sum);
}

int main(){
    node* root = newNode(6);
    /* Construct below tree
			 6
		   /  \
		  /    \
		 3      8
			   /  \
			  /    \
			 4      2
		   /   \      \
		  /     \      \
		 1       7      3
    */


    root->left = newNode(3);
    root->right = newNode(8);
    root->right->left = newNode(4);
    root->right->right = newNode(2);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(3);


    truncate(root, 20);
    inorder(root);

    return 0;
}
