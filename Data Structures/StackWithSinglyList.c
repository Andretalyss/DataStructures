#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int size;
    struct NodeOfPile* head;
    struct NodeOfPile* tail;
}List;

typedef struct NodeOfPile{
    int value;
    struct NodeOfPile* next;

}NodeOfPile;

void initialize(List *n){
    
    n->size = 0;
    n->head = NULL;
    n->tail = NULL;
}

void push(List *n, int value){
    NodeOfPile *new = (NodeOfPile*) malloc(sizeof(NodeOfPile));
    //printf("Entrou1\n");

    if(n->head == NULL){
        //printf("Entrou\n");
        n->head = new;
        n->tail = new;
        new->next = NULL;
        new->value = value;
        n->size++;

    }else{
        //printf("Entrou2\n");
        new->next = n->tail;
        n->tail = new;
        new->value = value;
        n->size++;
    }
}

void print(List *p){
    if(p->tail){
        printf(" ---  TOP OF PILE ---\n\n");
        while(p->tail){
        printf("     ---  %d  --- \n", p->tail->value);
        p->tail = p->tail->next;
    }
        printf("\n --- FLOOR OF PILE ---\n");
    }else{
        printf("Empty Pile\n");
    }
    
}

int pop(List *n){   
    NodeOfPile *remov;

    if(n->size == 0)
        return 0;

    remov = n->tail;
    n->tail = n->tail->next;
   
    free(remov);
    n->size--;
   
   return 1;
}

int main(int argc, char*argv[]){

    List* p;
    p = (List*) malloc(sizeof(List));
    initialize(p);

    printf("What's your choice?\n");
    printf("[1]Add {push} or [0]Remove {pop} -> ");  

    int choice;
    scanf("%d", &choice);

    if(choice){
        for(int i=0;i<6;i++){
        printf("Enter with the value: ");
        int value;
        scanf("%d", &value);
        push(p, value);
     }}

    
    int aux = pop(p);
    if(aux)
        printf("\n~> The last add was deleted <~\n\n");
    else{
        printf("Empty Pile\n");
        return 0;
    }
    
    print(p);

    return 0;
}