#ifndef LIST_H
#define LIST_H

#ifndef NULL
#define NULL (void*)0
#endif //NULL

typedef struct ListItem {
    struct ListItem* prev;
    struct ListItem* next;
    void* value;
} ListItem;

typedef struct List {
    ListItem* root_item;
    ListItem* current_item;
} List; 

typedef void (*deleter)(void* value);

List* List_new(void);
void List_delete(List* list, deleter del_func);
void List_rewind(List* list);
void* List_get_next(List* list);
int List_add(List* list, void* value);
int List_has_next(List* list);

//Iterates through the values stored in list, placing each into variable value which is of type type 
#define List_for_each(list, value, type) for(List_rewind(list); ((value) = (type)List_get_next(list)); )

#endif //LIST_H