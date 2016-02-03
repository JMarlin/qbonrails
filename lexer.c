#include <stdio.h>
#include <memory.h>
#include "List.h"

typedef struct token_tree {
    int child_count;              //The number of child trees that are hanging off of this node
    string* rule_type;            //The rule that was matched to make this node 
    string* value;                //The actual characters matched 
    struct token_tree* parent;    //
    struct token_tree* children;
} token_tree;

//Given a parent, allocates, attaches and returns a new child
token_tree* tt_add_child(token_tree* parent_root) {
    
}

typedef struct LexerRule {
    char* name;
    char* rule;
} LexerRule;

List* lexer_rules = (List*)0;

int lexer_init() {
    
    LexerRule* rule;
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
    
    return List_add(lexer_rules, new_rule);
}

void lexer_print_rules(void) {
    
    LexerRule* rule;
    int i = 0;
    
    List_for_each(lexer_rules, rule, LexerRule*)
        printf("lexer_rules['%s']: %s\n", rule->name, rule->rule);
}

token_tree* lexer_run(char* input_string) {
    
    //Create a new empty token tree
    token_tree* output_tree = new_token_tree();
    
    //Fail if we couldn't allocate the object
    if(!output_tree)
        return output_tree;
        
    //Start trying to recursively match the content against the user's rules
    lexer_match(input_string, output_tree);
}

//Recursively attempts to pattern match on the user-defined grammar to produce a tree of matched tokens 
//Takes a pointer into the string to be matched and the parent node that any matches will be hung off of 
//As it matches, it calls itself as soon as it reads a sub-rule name and passes itself the parsed string
//
int lexer_match(char* input_string, token_tree* tree_root){
    
}

//Takes an offset into a string to begin matching and the rule to match and returns the number of
//characters in the match on success or a negative value on failure 
int lexer_match_on_rule()