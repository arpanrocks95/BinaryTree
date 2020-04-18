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
struct  pairinc{
    int first ;
    int second;
};
struct pairinc * newPair(int first,int second){
    struct pairinc *  temp = (struct pairinc * ) malloc(sizeof(struct pairinc));
    temp->first = first;
    temp->second = second;
}
struct  mapinc{
    int key ;
    struct pairinc * point;
    int array[10] ;
    int count;
    struct mapinc * next;
};
struct mapinc * mapper = NULL;
int sizeofmap(){
    int size= 0;
    struct mapinc *  iter =  mapper;
    while(iter != NULL){
        size++;
        iter = iter->next;
    }
    return size;
}
void insertInMap(struct pairinc * pair,int key){
    struct mapinc *  temp = (struct mapinc *) malloc(sizeof(struct mapinc));
    temp->key =  key;
    temp->point = pair;
    temp->next = NULL;
    temp->count = 0;
    int condition = 1;
    if(mapper == NULL){
        mapper = temp;
    } else{
        struct mapinc *  iter =  mapper;
        while(iter != NULL && condition){

            if(iter->key == temp->key){
                iter->point = temp->point;
                condition = 0;
                iter->array[iter->count++] = iter->point->first;
                return ;
            }
            iter = iter->next;

        }
        if(condition == 1){
            temp->array[temp->count++] = temp->point->first;
            temp->next = mapper;
            mapper = temp;

        }
    }

}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void viewmap(){
    int array[10];
    int count = 0;
    struct mapinc *  iter =  mapper;
    if(iter == NULL){
        return;
    }
    while(iter != NULL){
        array[count++] = iter->key;
        iter = iter->next;
    }
    bubbleSort(array,count +1);

    for (int i = 0; i < count+1; ++i) {
        iter =  mapper;
        while(iter != NULL){
            if(array[i] == iter->key){
                for (int i = 0; i < iter->count ; ++i) {
                    printf("%d ",iter->array[i]);
                }
                printf("\n");
            }
            iter = iter->next;
        }
    }

}



/*function for level order traversal iteratively*/
void verticalTraversalOfTheTreeRecursively(node *root, int distance, int level)
{
    if (root == nullptr)
        return;
    struct pairinc * pair1 = newPair(root->key,level);
    insertInMap(pair1,distance);
    verticalTraversalOfTheTreeRecursively(root->left, distance - 1, level + 1);
    verticalTraversalOfTheTreeRecursively(root->right, distance + 1, level + 1);
}
void printVericalTraversalRecursively(node * root){
    verticalTraversalOfTheTreeRecursively(root, 0, 0);
    viewmap();

}

int main(){
    /* Construct below tree
          1
        /   \
       /     \
      2       3
            /   \
           /     \
          5       6
        /   \
       /     \
      7       8
    */

    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);
    printVericalTraversalRecursively(root);
    return 0;
}
