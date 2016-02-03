#ifndef LEXER_H
#define LEXER_H

typedef struct LexerRule {
    char* name;
    char* rule;
} LexerRule;

int lexer_init();
int lexer_add_rule(char* name, char* rule);
void lexer_print_rules(void);
struct token_tree* lexer_run(char* input_string);
int lexer_match(char* input_string, struct token_tree* tree_root);
int lexer_match_on_rule();

#endif //LEXER_H
