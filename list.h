typedef struct ListItem {
    struct ListItem* prev;
    struct ListItem* next;
    void* value;
} ListItem;

typedef struct List {
    ListItem* root_item;
    ListItem* current_item;
} List; 

List* List_new(void);
void List_rewind(List* list);
void* List_get_next(List* list);
void List_add(List* list, void* value);

inline int List_has_next(List* list) {
    
    return !!(list->current_item && list->current_item->next);
}

//Iterates through the values stored in list, placing each into variable value which is of type type 
#define List_for_each(list, value, type) for(rewind_List(list); List_has_next(list); (value) = (type)List_get_next())