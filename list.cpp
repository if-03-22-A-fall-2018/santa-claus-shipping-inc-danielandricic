
#include <stdlib.h>
#include "list.h"

struct _node{
  Node* next;
  void* data;
};

struct _list{
  Node* head;
  Node* tail;
  int count;
};

List* list_create()
{
 List *list = (List*) malloc(sizeof(List));
 list->head = 0;
 return list;
}

/*
 * Used to free all memory the supplied list allocated
 * (hint: list structure, including the list itself, but not the data!)
 */

 void list_delete(List *list){
   int length = list_get_length(list);

   for(int i = 0; i < length; i++){
     Node* head = list->head;
     list->head = head->next;
     free(head);
   }

   free(list);
 }
/*
 * Adds a new node with the supplied data to the start of the list
 */

void list_add(List *list, void *data)
{
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;

  if(list->head == 0)
  {
    list->head = newNode;
    list->head->next = 0;
  }
  else
  {
    newNode->next = list->head;
    list->head = newNode;
  }
}
/**
 * Adds a new node with the supplied data after the supplied node
 */

void list_insert_after(Node *node, void *data)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = node->next;
  node->next = newNode;
}
/**
 * Return the head of the list
 */

Node* list_get_first(List *list)
{
  return list->head;
}

/**
 * Returns the next node in the list
 * (hint: be careful if the last node in the list is supplied)
 */

Node* list_get_next(Node *node)
{
  return node->next;
}
/**
 * Retrieves the data stored in the supplied node
 * (hint: you'll probably won't be able to use this void* without casting)
 */

void* list_get_data(Node *node)
{
  return (void*) node->data;
}

int list_get_length(List* list)
{
  int count = 0;
  Node* currentnode = list->head;

  while(currentnode != 0)
  {
    count++;
    currentnode = currentnode->next;
  }
  return count;
}

void list_delete_data_of_node(List *list)
{
  int length = list_get_length(list);
  Node* currentnode = list->head;

  for(int i = 0; i < length; i++)
  {
    free(list_get_data(currentnode));
    currentnode = currentnode->next;
  }
}
