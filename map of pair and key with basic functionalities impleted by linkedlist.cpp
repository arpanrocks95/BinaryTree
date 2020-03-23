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
            }
            iter2 = iter2->next;
        }iter1 = iter1->next;
    }
}
void viewmap(){
    sortmapinc(sizeofmap());
    struct mapinc *  iter =  mapper;
    if(iter == NULL){
        return;
    }

    while(iter != NULL){
        printf("key :%d  and pair is (%d , %d) \n",iter->key,iter->point->first,iter->point->second);
        iter = iter->next;
    }

}

int main(){

    struct pairinc * pair1 = newPair(1,2);
    struct pairinc * pair2 = newPair(3,4);
    struct pairinc * pair3 = newPair(5,6);
    struct pairinc * pair4 = newPair(7,8);
    struct pairinc * pair5 = newPair(9,10);
    struct pairinc * pair6 = newPair(11,12);

    insertInMap(pair1,10);
    insertInMap(pair2,20);
    insertInMap(pair3,20);
    insertInMap(pair4,30);
    insertInMap(pair5,40);
    insertInMap(pair6,50);
    viewmap();


    return 0;
}
