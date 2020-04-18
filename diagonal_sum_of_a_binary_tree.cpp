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




/*building a map for storing a pair and key */

struct  mapinc{
    int key ;
    int sum;
    struct mapinc * next;
};
struct mapinc * mapper = NULL;

void insertInMap(int sum,int key){
    struct mapinc *  temp = (struct mapinc *) malloc(sizeof(struct mapinc));
    temp->key =  key;
    temp->sum = sum;
    temp->next = NULL;
    int condition = 1;
    if(mapper == NULL){
        mapper = temp;
    } else{
        struct mapinc *  iter =  mapper;
        while(iter != NULL && condition){

            if(iter->key == temp->key){
                condition = 0;
                iter->sum = iter->sum + temp->sum;
                return ;

            }
            iter = iter->next;

        }
        if(condition == 1){
            temp->next = mapper;
            mapper = temp;
        }
    }

}






void viewmap(){

    struct mapinc *  iter =  mapper;
    if(iter == NULL){
        return;
    }
    while(iter != NULL){
        printf("%d ",iter->sum);
        iter = iter->next;
    }


}



/*function for level order traversal iteratively*/
void verticalTraversalOfTheTreeRecursively(node *root, int diagonal)
{
    if (root == nullptr)
        return;
    insertInMap(root->key,diagonal);
    verticalTraversalOfTheTreeRecursively(root->left,diagonal +1);
    verticalTraversalOfTheTreeRecursively(root->right, diagonal);
}
void diagonalSum(node * root){
    verticalTraversalOfTheTreeRecursively(root, 0);
    viewmap();

}

int main(){
    node* root = newNode(1);

    /* Construct below tree
              1
            /  \
           /    \
          2      3
         /     /  \
        /     /    \
       4     5     6
            / \
           /   \
          7     8
    */


    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);

    diagonalSum(root);

    return 0;
}
