#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lexer.h"

List* lexer_rules = (List*)0;

int lexer_init() {
    
    lexer_rules = List_new();
    
    if(!lexer_rules)
        return 0;
    
    return 1;
}

int lexer_add_rule(char* name, char* rule) {
    
    LexerRule* new_rule;
    
    if(!lexer_rules)
        return 0;
        
    new_rule = (LexerRule*)malloc(sizeof(LexerRule));
    
    if(!new_rule)
        return 0;
        
    new_rule->name = name;
    new_rule->rule = rule;
    
    return List_add(lexer_rules, (void*)new_rule);
}

void lexer_print_rules(void) {
    
    LexerRule* rule;
    
    List_for_each(lexer_rules, rule, LexerRule*) {
            
        printf("lexer_rules['%s']: %s\n", rule->name, rule->rule);
    }
}

token_tree* lexer_run(char* input_string) {
    
    //Create a new empty token tree
    TokenTree* output_tree = TokenTree_new("document", (char*)0);
    
	if(!output_tree)
	    return output_tree;
	
    //Fail if we couldn't allocate the object
    //if(!output_tree)
    //    return output_tree;
        
    //Start trying to recursively match the content against the user's rules
    //lexer_match(input_string, output_tree);
	
	return output_tree;
}

//Recursively attempts to pattern match on the user-defined grammar to produce a tree of matched tokens 
//Takes a pointer into the string to be matched and the parent node that any matches will be hung off of 
//As it matches, it calls itself as soon as it reads a sub-rule name and passes itself the parsed string
//
int lexer_match(char* input_string, token_tree* tree_root){
    
	return 0;
}

//Takes an offset into a string to begin matching and the rule to match and returns the number of
//characters in the match on success or a negative value on failure 
int lexer_match_on_rule() {
    
	return 0;
}