#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List * list = (List *)malloc(sizeof(List));
  if(list == NULL) exit(EXIT_FAILURE);

  list -> head = NULL;
  list -> current = NULL;
  list -> tail = NULL;
  return list;
}

void * firstList(List * list) {
  if(list == NULL || list -> head == NULL) return NULL;
  
  list -> current = list -> head;
  return list->head-> data;
}

void * nextList(List * list) {
  if(list == NULL || list -> current == NULL || list -> current -> next == NULL) return NULL;
  list -> current = list -> current -> next;
  void * data = list -> current -> data;
  return data;
}

void * lastList(List * list) {
  if(list == NULL || list -> tail == NULL) return NULL;
  list -> current = list -> tail;
  void * dato = list -> tail -> data;
  
  return dato;
}

void * prevList(List * list) {
  if(list == NULL || list -> current == NULL || list -> current -> prev == NULL) return NULL;
  void * dato = list -> current -> prev -> data;
  list -> current = list -> current -> prev;
  return dato;
}

void pushFront(List * list, void * data){
  Node* newNodo = createNode(data);
  if(list == NULL) exit(EXIT_FAILURE);
  newNodo -> next = list -> head;
  list-> head -> prev = newNodo;
  list -> head = newNodo;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}