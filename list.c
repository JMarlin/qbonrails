#include <stdlib.h>
#include "list.h"

List* List_new(void) {
    
    List* ret_list = (List*)malloc(sizeof(List));
    
    if(!ret_list)
        return ret_list;
        
    ret_list->root_item = (ListItem*)0;
    List_rewind(ret_list);
    
    return ret_list;
}

//Deletes all elements of the list, and deletes the contained values
//using the passed delete function
void List_delete(List* list, deleter del_func) {
	
	ListItem* current_item = list->root_item;
	ListItem* prev_item;
	
	if(current_item) {
		
		//Fast forward to the end of the list
		while(current_item->next)
		    current_item = current_item->next;
			
	    //Delete in reverse order
		while(current_item) {
		
		    //Temporarily store the previous element so that we don't lose it
		    prev_item = current_item->prev;
			
			//Use the supplied deleter to delete the lite item's value 
			del_func(current_item->value);
			
			//Finally, get rid of the current ListItem and move back down the list
			free((void*)current_item);
			current_item = prev_item;    	
		}
	}
	
	//Now that we've deleted all of the content, we can free the root object
	free((void*)list);
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
        return (void*)0;
    
    ret_val = list->current_item->value;
    
    if(list->current_item)
        list->current_item = list->current_item->next;
        
    return ret_val;
}

int List_has_next(List* list) {
    
    return !!(list->current_item);
}
