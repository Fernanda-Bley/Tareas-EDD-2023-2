#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

// Funciones

// Funcion que crea un nodo

Node* init_node(int value){
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("No se pudo crear el nodo");
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

// Funcion que crea una lista

List *createList(){
    List *list = (List *) malloc(sizeof(List));
    if (list == NULL) {
        printf("No se pudo crear la lista");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
};

void add(List *list, int value){
    Node *node = init_node(value);
    if (node == NULL) {
        printf("Error: no se pudo agregar el nodo\n");
        return;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}};
void delete(List *list, int value){
    if (list->head == NULL) {
        printf("Error: la lista está vacía\n");
        return;
    }
    Node *aux = list->head;
    Node *prev = NULL;
    while (aux != NULL) {
        if (aux->value == value) {
            if (prev == NULL) {
                list->head = aux->next;
            } else {
                prev->next = aux->next;
            }
            free(aux);
            list->size--;
            return;
        }
        prev = aux;
        aux = aux->next;
    }
};
void printList(List *list){
    Node *aux = list->head;
    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
};
void deleteList(List *list){
    Node *aux = list->head;
    
    while (aux != NULL) {
        Node *temp = aux;
        aux = aux->next;
        free(temp);
    }
    
    free(list);
};

int search(List *list, int value){
    Node *aux = list->head;
    int pos = 0;
    while (aux != NULL) {
        if (aux->value == value) {
            return pos;
        }
        pos++;
        aux = aux->next;
    }
    return -1;
};

void insertAt(List *list, int value, int pos){
    Node *node = init_node(value);
    Node *aux = list->head;
    Node *prev = NULL;
    int i = 0;
    while (aux != NULL) {
        if (i == pos) {
            if (prev == NULL) {
                node->next = list->head;
                list->head = node;
            } else {
                prev->next = node;
                node->next = aux;
            }
            list->size++;
            return;
        }
        prev = aux;
        aux = aux->next;
        i++;
    }
};

void deleteAt(List *list, int pos){
    if(pos<0 || pos>list -> size){
       printf("Error: posición inválida\n"); 
       return; 
   }
   Node *aux = list->head;
   Node *prev = NULL;
   int i = 0;
   while (aux != NULL) {
    if (i == pos) {
        if (prev == NULL) {
            list->head = aux->next;
        } else {
            prev->next = aux->next;
        }
        free(aux);
        list->size--;
        return;
    }
        prev = aux;
        aux = aux->next;
        i++;
    }
};
