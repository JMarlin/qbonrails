#ifndef TOKENTREE_H
#define TOKENTREE_H

typedef struct TokenTree {
    char* type;            //The rule that was matched to make this node 
    char* value;                //The actual characters matched 
    struct TokenTree* parent;    
    struct List* children;
} TokenTree;

TokenTree* TokenTree_new(char* new_type, char* new_value);
void TokenTree_delete(TokenTree* token_tree);
TokenTree* TokenTree_add_child(TokenTree* root, char* new_type, char* new_value);
void TokenTree_print(TokenTree* token_tree);

#endif //TOKENTREE_H