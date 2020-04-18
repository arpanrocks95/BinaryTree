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

void inorderINsertingofnodesinarray(struct node * root,int * array,int &count){
    if (root == NULL) return;
    inorderINsertingofnodesinarray(root->left,array,count);
    array[count++] = root->key;
    inorderINsertingofnodesinarray(root->right,array,count);
}
void placeNodesInTreeCorrectly(struct node * root,int * array,int &count){
    if (root == NULL) return;
    placeNodesInTreeCorrectly(root->left,array,count);
    root->key =  array[count++] ;
    placeNodesInTreeCorrectly(root->right,array,count);
}
void inOrder(struct node * root){
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->key);
    inOrder(root->right);
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}



void coverstBinaryTreeToBST(node* root)
{   int arr[20];
    int count = 0;

    inorderINsertingofnodesinarray(root,arr,count);
    selectionSort(arr,count);
    count = 0;
    placeNodesInTreeCorrectly(root,arr,count);
    inOrder(root);
}

int main(){
/* Construct below tree
			  8
			/   \
		   /	 \
		  3	   5
		 / \	 / \
		/   \   /   \
	   10	2 4	 6   */

    node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(10);
    root->left->right = newNode(2);
    root->right->left = newNode(4);
    root->right->right = newNode(6);

    coverstBinaryTreeToBST(root);

    return 0;
}
