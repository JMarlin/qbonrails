#ifndef TOKENTREE_H
#define TOKENTREE_H

typedef struct TokenTree {
    char* type;            //The rule that was matched to make this node 
    char* value;                //The actual characters matched 
    struct token_tree* parent;    
    struct List* children;
} TokenTree;

TokenTree* TokenTree_new(char* new_type, char* new_value);
TokenTree_delete(TokenTree* token_tree);
TokenTree* TokenTree_add_child(TokenTree* root);
TokenTree_print(TokenTree* token_tree);

#endif //TOKENTREE_H