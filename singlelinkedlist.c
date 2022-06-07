/*  
    singlelinkedlist.c
    Nombre: Chelsea Durazo Duarte
    Fecha:  25/02/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "singlelinkedlist.h"

void print_list (struct node* list);
void free_list(struct node** list);

int main(){
    struct node* head = NULL;
    head = (struct node*) malloc(sizeof(struct node));

    head->e = 1;
    head->next = NULL;

    int result = append(head, 2);
    printf("\nResult: %d \n", result);

    result = append(head, 3);
    printf("\nResult: %d \n", result);
    print_list(head);

    result = remove_at(&head, 0);
    printf("\nResult: %d \n", result);
    print_list(head); 

    result = insert_at(&head, 10, 1);
    printf("\nResult: %d \n", result);
    print_list(head);

    result = reverse(&head);
    printf("\nResult: %d \n", result);
    print_list(head);    

    free_list(&head);

    return 0;
}

void print_list (struct node* list){

    struct node *ptr = list;
    if (list == NULL) printf("La lista no tiene elementos.\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->e);
        ptr = ptr->next;
    }
    
}

int count_nodes (struct node* list){

    struct node *ptr = list;
    int count = 0;
    if (list == NULL) return count;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int append (struct node* list, int e){

    struct node *ptr, *temp;
    ptr = list;
    temp = (struct node*) malloc(sizeof(struct node));

    (*temp).e = e;
    (*temp).next = NULL;

    while((*ptr).next != NULL){
        ptr = (*ptr).next;
    }
    (*ptr).next = temp;

    return 0;
}

int remove_at(struct node** list, int i){

    int nodes = count_nodes(*list);
    if(nodes <= i){
        printf("La lista solo tiene %d elementos", nodes);
        return 1;
    }

    struct node *ptr, *temp;
    int cont = 1;
    ptr = *list;
    temp = NULL;

    if(i == 0){ 
        *list = ptr->next;
        free(ptr);
        ptr = NULL;
        return 0;
    }

    while(cont < i){
        ptr = ptr->next;
        cont ++;
    }

    if(ptr->next == NULL){
        free(ptr->next);
        ptr->next = NULL;
        return 0;
    }

    temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
    temp = NULL;

    return 0;
}


int insert_at(struct node** list, int e, int i){

    int nodes = count_nodes(*list);
    if(nodes <= i){
        printf("La lista solo tiene %d elementos", nodes);
        return 1;
    }

    struct node *new = (struct node*) malloc(sizeof(struct node));
    
    new->e = e;
    new->next = NULL;

    if(i == 0){ 
        new->next = *list;
        *list = new;
        return 0;
    }

    struct node *ptr;
    int cont = 1;
    ptr = *list;

    while(cont < i){
        ptr = ptr->next;
        cont ++;
    }

    if(ptr->next == NULL){
        ptr->next = new;
        return 0;
    }

    new->next = ptr->next;
    ptr->next = new;

    return 0;
}

int reverse(struct node** list){
    struct node *ptr = *list, *prev = NULL, *nxt = NULL;

    while(ptr != NULL){
        nxt = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nxt;
    }
    *list = prev;

    return 0;
}

void free_list(struct node** list){

    if (*list == NULL) {
        printf("La lista no tiene elementos.\n");
        return;
    }
    if ((*list)->next == NULL) {
        free(*list);
        list == NULL;
        return;
    }
    struct node *temp;
    while (*list != NULL)
    {
        temp = *list;
        printf("Eliminado: %d ", (*list)->e);
        *list = temp->next;
        free(temp);
        temp = NULL;
        
    }
    return;
}