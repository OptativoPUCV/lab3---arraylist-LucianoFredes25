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
  List->capacity = 2;
  List->data = (void **) malloc(sizeof(void *) * (List->capacity));
  List->size = 0;
  return List;
}

void append(ArrayList * l, void * data){
  if(l->size == l->capacity){
    l->capacity = l->capacity * 2;
    l->data = realloc(l->data , l->capacity);
  }
  l->data[l->size] = data;
  l->size ++;
}

void push(ArrayList * l, void * data, int i){
  if(l->size == l->capacity){
    l->capacity = l->capacity * 2;
    l->data = realloc(l->data , l->capacity);
  }
  if(i != l->size){
    for(int j = l->size ; j > i ; j--)
      l->data[j]= l->data[j-1];
  }
  l->data[i] = data;
  l->size ++;
}

void* pop(ArrayList * l, int i){
  if(l->data[0] == NULL)
    return NULL;
  
  if(i != l->size && i >= 0){
    void * Aux = l->data[i];
    for(int j = i ; j < l->size - 1; j++)
      l->data[j]= l->data[j+1];
    l->size --;
    return Aux;
  }
  else{
    void * Aux2 = l->data[l->size + i];
    for(int j = l->size + i ; j < l->size - 1; j++)
      l->data[j]= l->data[j+1];
    l->size --;
    return Aux2;
  }
  
}

void* get(ArrayList * l, int i){
  if(i >= l->size)
    return NULL;
  if(i >= 0)
    return l->data[i];
  else
    return(l->data[l->size + i]);
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
