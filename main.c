#include <stdio.h>
#include "lexer.h"
#include "tokentree.h"

int main(int argc, char* argv[]) {
    
    TokenTree* tt_source;
    char* text_source = "PRINT \"Hello, World!\"";
    
    if(!lexer_init()) {
        
        printf("Lexer initialization failed.\n");
        return 1; 
    }

    lexer_add_rule("literal_string", "\"(c*)\"");
    lexer_add_rule("literal", "[literal_string]");
	lexer_add_rule("statement", "[print_statement]\n");
    lexer_add_rule("print_statement", "PRINT(w*)[literal](w*)");
    printf("\nLexer rules:\n--------------------\n");
	lexer_print_rules();
    tt_source = lexer_run(text_source);
	printf("\nToken tree:\n--------------------\n");
    TokenTree_print(tt_source);
	
	return 0;
}