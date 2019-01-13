#include "child_data_mgmt.h"
#include <stdlib.h>

struct _childDataMgmt{
 List* list;
};

ChildDataMgmt* cdm_create(){
  ChildDataMgmt* current = (ChildDataMgmt*) malloc(sizeof(ChildDataMgmt));
  current->list = list_create();
  return current;
}

void cdm_add_data(ChildDataMgmt *cdm, ChildData *data){
  Node* currentnode = list_get_first(cdm->list);
  Node* last_node_of_city = 0;

  while(currentnode != 0)
  {
    if(((ChildData*)list_get_data(currentnode))->city == data->city)
    {
      last_node_of_city = currentnode;
    }
    else if((list_get_next(currentnode) == 0) && (last_node_of_city == 0))
    {
      last_node_of_city = currentnode;
    }
    currentnode = list_get_next(currentnode);
  }

  if(last_node_of_city == 0)
  {
    list_add(cdm->list, data);
  }
  else
  {
    list_insert_after(last_node_of_city, data);
  }
}

Node* cdm_get_sorted_data(ChildDataMgmt *cdm)
{
  return list_get_first(cdm->list);
}

void cdm_delete(ChildDataMgmt *cdm)
{
  list_delete(cdm->list);
  free(cdm);
}
