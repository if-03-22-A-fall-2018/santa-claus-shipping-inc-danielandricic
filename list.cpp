#include <stdlib.h>
#include "list.h"

struct _node{
  Node* _next;
  void* _data;
};

struct _list{
  Node* _head;
  Node* _tail;
  int count;
};

List* list_create()
{
 List *list = malloc(sizeof(List));
 return list;
}
/**
 * Used to free all memory the supplied list allocated
 * (hint: list structure, including the list itself, but not the data!)
 */
void list_delete(List *list)
{
  free(list);
}
/**
 * Adds a new node with the supplied data to the start of the list
 */
void list_add(List *list, void *data)
{
  Node newNode = (Node*)malloc(sizeof(Node));
  newNode->_data = data;

  if(list->_head)
  {
    list->_head = newNode;
    return;
  }
  newNode->_next = list->_head;
}
/**
 * Adds a new node with the supplied data after the supplied node
 */
void list_insert_after(Node *node, void *data)
{

}
/**
 * Return the head of the list
 */
Node* list_get_first(List *list)
{
  return list->_head;
}

/**
 * Returns the next node in the list
 * (hint: be careful if the last node in the list is supplied)
 */
Node* list_get_next(Node *node)
{
  return 0;
}
/**
 * Retrieves the data stored in the supplied node
 * (hint: you'll probably won't be able to use this void* without casting)
 */
void* list_get_data(Node *node)
{
  return 0;
}
