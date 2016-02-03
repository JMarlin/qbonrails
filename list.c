#include <stdlib.h>
#include "list.h"

List* List_new(void) {
    
    List* ret_list = (List*)malloc(sizeof(List));
    
    if(!ret_list)
        return ret_list;
        
    ret_list->root_item = (ListItem)0;
    List_rewind(ret_list);
    
    return ret_list;
}

void List_rewind(List* list) {
    
    list->current_item = list->root_item;
}

int List_add(List* list, void* value) {
    
    ListItem* current_item;
    ListItem* new_item = (ListItem*)malloc(sizeof(ListItem));
    
    if(!new_item)
        return 0;    
    
    new_item->value = value;
    new_item->next = (ListItem*)0;
        
    if(!list->root_item) {
        
        list->root_item = new_item;
        list->current_item = new_item;
    } else {
        
        current_item = list->root_item;
        
        while(current_item->next)
            current_item = current_item->next;
            
        new_item->prev = current_item;
        current_item->next = new_item; 
    }
    
    return 1;
}

void* List_get_next(List* list) {
    
    void* ret_val;
    
    if(!list->current_item) 
        return;
    
    ret_val = list->current_item->value;
    
    if(list->current_item->next)
        list->current_item = list->current_item->next;
        
    return ret_val;
}