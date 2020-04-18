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
    struct mapinc * next;
};
struct mapinc * mapper = NULL;
void insertInMap(struct pairinc * pair,int key){
    struct mapinc *  temp = (struct mapinc *) malloc(sizeof(struct mapinc));
    temp->key =  key;
    temp->point = pair;
    temp->next = NULL;
    int condition = 1;
    if(mapper == NULL){
        mapper = temp;
    } else{
        struct mapinc *  iter =  mapper;
        while(iter != NULL && condition){
            if(iter->key == temp->key){
                condition = 0;
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
        printf("key :%d  and pair is (%d , %d) \n",iter->key,iter->point->first,iter->point->second);
        iter = iter->next;
    }

}


/*function for level order traversal iteratively*/
void topViewOfTheTreeRecursively(node *root, int distance, int level)
{
    if (root == nullptr)
        return;
    struct pairinc * pair1 = newPair(root->key,level);
    insertInMap(pair1,distance);
    topViewOfTheTreeRecursively(root->left, distance - 1, level + 1);
    topViewOfTheTreeRecursively(root->right, distance + 1, level + 1);
}
void printtopViewOfTheTreeRecursively(node * root){
    topViewOfTheTreeRecursively(root, 0, 0);
    sortmapinc();
    struct mapinc *  iter =  mapper;
    while(iter != NULL){
        printf("%d ",iter->point->first);
        iter = iter->next;
    }

}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);
    printtopViewOfTheTreeRecursively(root);

    return 0;
}
