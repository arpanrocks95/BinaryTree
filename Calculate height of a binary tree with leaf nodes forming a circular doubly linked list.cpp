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



int getHeight(struct  node *root){
    if (root == NULL) return 0;
    if((root->left == NULL && root->right == NULL) || ((root->left && root->left->right == root) && (root->right && root->right->left == root))) return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if(left>right)  return left+1;
    else return right+1;
}


void height(node* root)
{
    int count = getHeight(root);

    printf("%d is the height",count);
}

int main(){
/* Construct below tree
			  1
			/   \
		   /	 \
		  2	      3
		 / \	 / \
		/   \   /   \
	   4	 5 ------6
      /    /
     7----


	   */

    struct node* root = newNode(1);

    // construct the tree

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);		// leaf node
    root->right->right = newNode(6);   	// leaf node
    root->left->left->left = newNode(7);   // leaf node

    // construct circular doubly linked list from leaves
    struct node *L1 = root->left->left->left;
    struct node *L2 = root->left->right;
    struct node *L3 = root->right->right;

    // set previous and next pointers of the linked list
    // (left and right pointer of binary tree node respectively)
    L1->left = L3;
    L1->right = L2;

    L2->left = L1;
    L2->right = L3;

    L3->left = L2;
    L3->right = L1;

    height(root);

    return 0;
}
