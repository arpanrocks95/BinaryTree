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
    int sum ;
    struct mapinc * next;
};
struct mapinc * mapper = NULL;
void insertInMap(struct pairinc * pair,int key){
    struct mapinc *  temp = (struct mapinc *) malloc(sizeof(struct mapinc));
    temp->key =  key;
    temp->point = pair;
    temp->next = NULL;
    temp->sum = pair->first;
    int condition = 1;
    if(mapper == NULL){
        mapper = temp;
    } else{
        struct mapinc *  iter =  mapper;
        while(iter != NULL && condition){

            if(iter->key == temp->key){
                iter->sum = iter->sum + temp->point->first;
                iter->point = temp->point;
                condition = 0;

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
int sizeofmap(){
    int size= 0;
    struct mapinc *  iter =  mapper;
    while(iter != NULL){
        size++;
        iter = iter->next;
    }
    return size;
}
void sortmapinc(){
    struct mapinc *  iter1 =  mapper;

    while (iter1 != NULL){
        struct mapinc *  iter2 =  iter1->next;
        while(iter2 != NULL){

            if(iter1->key > iter2->key){
                struct pairinc *temppair = iter1->point;
                iter1->point = iter2->point;
                iter2->point = temppair;
                int tempkey = iter1->key;
                iter1->key = iter2->key;
                iter2->key = tempkey;
                int sum = iter1->sum;
                iter1->sum = iter2->sum;
                iter2->sum = sum;
            }
            iter2 = iter2->next;
        }iter1 = iter1->next;
    }
}
void viewmap(){
    sortmapinc();
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
void bottomViewOfTheTreeRecursively(node *root,int distance, int level)
{
    if (root == nullptr)
        return;
    struct pairinc * pair1 = newPair(root->key,level);
    insertInMap(pair1,distance);
    bottomViewOfTheTreeRecursively(root->left, distance - 1, level + 1);
    bottomViewOfTheTreeRecursively(root->right, distance + 1, level + 1);
}
void printbottomViewOfTheTreeRecursively(node * root){
    bottomViewOfTheTreeRecursively(root, 0, 0);
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
    printbottomViewOfTheTreeRecursively(root);
    return 0;
}
