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


int printThePathOFMaxSum(node* root, int sum)
{

    if (sum == 0)
        return 1;

    if(root == NULL) return 0;

    int left = printThePathOFMaxSum(root->left,sum - root->key);
    int right = printThePathOFMaxSum(root->right,sum - root->key);

    if(left || right){
        printf("%d ",root->key);

    }
    return left || right;

}
int findmaximumsuminapath(struct node *root){

    if (root == NULL)
        return 0;
    int left = findmaximumsuminapath(root->left);
    int right = findmaximumsuminapath(root->right);
    return (left > right ? left : right) + root->key;

}

void findMaxSumPath(node* root)
{
    int sum = findmaximumsuminapath(root);
    printf("%d is the sum max in all paths of the binary tree and path is :    ",sum);
    printThePathOFMaxSum(root, sum);

}

int main(){
    node* root = newNode(1);
    /* Construct below tree
			  1
			/   \
		   /     \
		  2       3
		 / \     / \
		8   4   5   6
		   /   / \   \
		 10   7   9   5
    */


    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->left->right->left = newNode(10);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(9);
    root->right->right->right = newNode(5);

    findMaxSumPath(root);

    return 0;
}
