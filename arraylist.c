#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList * List = (ArrayList *) malloc(sizeof(ArrayList));
  for(int i = 0 ; i < 2 ; i++){
    List->data = (void *) malloc(sizeof(void *));
  }
  List->capacity = 2;
  List->size = 0;
  return List;
}

void append(ArrayList * l, void * data){
  if(l->size == l->capacity){
    l->capacity = l->capacity * 2;
    l->data = realloc(data , l->capacity);
  }
  l->data[l->size] = data;
}

void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
