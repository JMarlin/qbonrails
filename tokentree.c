#include <stdlib.h>
#include <string.h>
#include "tokentree.h"
#include "list.h"

void TokenTree_deleter(void* value);

char* strclone(char* input) {
	
	char* retstr = (char*)malloc(strlen(input) + 1);
	
	if(!retstr)
	    return retstr;
		
	strcpy(retstr, input);
	
	return retstr;
}

TokenTree* TokenTree_new(char* new_type, char* new_value) {
	
    TokenTree* new_tree = (TokenTree*)malloc(sizeof(TokenTree));
	
	if(!new_tree)
	    return new_tree;
	
	//Blank values 
	new_tree->type = (char*)0;
	new_tree->value = (char*)0;
	new_tree->parent = (TokenTree*)0;
	new_tree->children = (List*)0;
	
	//Clone rule type string 
	if(new_type)	
		if(!(new_tree->type = strclone(new_type))) {
			
			TokenTree_delete(new_tree);
			return (TokenTree*)0;
		}
	
	//Clone rule value string  	
	if(new_value)
		if(!(new_tree->value = strclone(new_value))) {
			
			TokenTree_delete(new_tree);
			return (TokenTree*)0;
		}
	
	//Create a new list for the child trees
	if(!(new_tree->children = List_new())) {
		
		TokenTree_delete(new_tree);
		return (TokenTree*)0;
	}
	
	return new_tree;
}

void TokenTree_delete(TokenTree* token_tree) {
	
	if(token_tree->type)
	    free((void*)token_tree->type);
	
	if(token_tree->value)
	    free((void*)token_tree->value);
	
	if(token_tree->children)	
	    List_delete(token_tree->children, TokenTree_deleter);
		
	free((void*)token_tree);
}

//The deleter wrapper for the TokenTree destructor
void TokenTree_deleter(void* value) {
	
	TokenTree_delete((TokenTree*)value);
}

//Given a parent, allocates, attaches and returns a new child
TokenTree* TokenTree_add_child(TokenTree* root, char* new_type, char* new_value) {
	
    TokenTree* new_tree = TokenTree_new(new_type, new_value);
	
	if(!new_tree)
	    return new_tree;

    //Insert the new tree into the parent's children list 	
	if(!List_add(root->children, (void*)new_tree)) {
		
		TokenTree_delete(new_tree);
		return (TokenTree*)0;
	}
	
	//Set the parent of the new tree to the supplied root 
	new_tree->parent = root;
	
	return new_tree;
}

//Recursively print the content of a token tree 
void TokenTree_print_at_level(TokenTree* token_tree, int level) {
	
	int i;
	TokenTree* child;
		
    if(!token_tree)
	    return;
		
	//Indent the current line by the current level 
	for(i = 0; i < level; i++)
	    printf("| ");
    
	//Print the type and value of the tree node
	printf("|-%s with ", token_tree->type);
	
	if(!strlen(token_tree->value))
	    printf("no value\n");
    else
	    printf("value '%s'\n", token_tree->value);
	
	//Print all of the children of this node one level deeper 
	if(!token_tree->children)
	    return;
		
	List_for_each(token_tree->children, child, TokenTree*)		
		TokenTree_print_at_level(child, level + 1);
}

void TokenTree_print(TokenTree* token_tree) {
	
	TokenTree_print_at_level(TokenTree* token_tree, 0);
}