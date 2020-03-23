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

void printAllThepathsofbinartree(node * root, int *array, int & count){
    if(root == NULL) return;
    array[count++] = root->key;
    if(root->left == NULL && root->right == NULL){
        for (int i = 0; i < count ; ++i)
            if(i+1 != count) printf("%d->",array[i]);
            else printf("%d",array[i]);
        printf("\n");
    }
    printAllThepathsofbinartree(root->left, array, count);
    printAllThepathsofbinartree(root->right, array, count);
    count--;
}

void FINDallPaths(node* root)
{
    int array[10];
    int count = 0;
    printAllThepathsofbinartree(root, array, count);

}


int main(){
    node* root = newNode(1);
    /* Construct below tree
          1
        /   \
       /     \
      2       3
     / \     / \
    4   5   6   7
           /     \
          8       9
    */

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->left = newNode(8);
    root->right->right->right = newNode(9);

    // print all root to leaf paths
    FINDallPaths(root);

    return 0;
}
