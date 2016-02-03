int main(int argc, char* argv[]) {
    
    token_tree* tt_source;
    text_source = "PRINT \"Hello, World!\""
    
    lexer_init();
    lexer_add_rule("literal_string", "");
    lexer_add_rule("literal", "[literal_string]");
    lexer_add_rule("print_statement", "PRINT(w*)[literal](w*)");
    lexer_add_rule("statement", "[print_statement]\n");
    
    tt_source = lexer_run(text_source);
    tt_print(tt_source);
}