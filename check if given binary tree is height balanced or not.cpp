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


void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}



int checkOfBlancedTree(node* root, int & balancedcondition)
{

    if (root == NULL || !balancedcondition)
        return 0;

    int left_height = checkOfBlancedTree(root->left, balancedcondition);


    int right_height = checkOfBlancedTree(root->right, balancedcondition);

    if (((left_height - right_height) > 1) || ((left_height - right_height) < -1))
        balancedcondition = 0;

    if(left_height > right_height) return left_height + 1;
    else return right_height +1;


}


void balanced(node* root)
{
    int balancedcondition  = 1;
    checkOfBlancedTree(root, balancedcondition);
    if (balancedcondition) printf("Yes its Balnaced \n");
    else printf("No Its Not Balanced\n");
}

int main(){
    node*  root = newNode(1);
    /* Construct below tree
			  1
			/   \
		   /     \
		  2       3
		 / \     /
		4   5   6
	*/



    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    balanced(root);



    return 0;
}
