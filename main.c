#include <stdio.h>
#include "lexer.h"

int main(int argc, char* argv[]) {
    
    token_tree* tt_source;
    char* text_source = "PRINT \"Hello, World!\"";
    
    if(!lexer_init()) {
        
        printf("Lexer initialization failed.\n");
        return 1; 
    }
    
    lexer_add_rule("literal_string", "\"(c*)\"");
    lexer_print_rules();
    lexer_add_rule("literal", "[literal_string]");
    lexer_print_rules();
    lexer_add_rule("print_statement", "PRINT(w*)[literal](w*)");
    lexer_print_rules();
    lexer_add_rule("statement", "[print_statement]");
    lexer_print_rules();
    
    //tt_source = lexer_run(text_source);
    //tt_print(tt_source);
	
	return 0;
}