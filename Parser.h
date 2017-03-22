#include "Tokeniser.c"
#include "AST.c"

typedef struct {
	
	Token** tokens;
	size_t position;
	size_t end_position;
	
} Parser;

void Parser_create(Parser* p, Token*** tokens);
void Parser_destroy(Parser* p);

// Parsers
void Parser_parse_program(Parser* p);

ExpressionValueTree Parser_parse_expression(Parser* p);
ExpressionValueTree Parser_parse_value(Parser* p);
CommandTree Parser_parse_definition(Parser* p);
CommandTree Parser_parse_if(Parser* p);

int Parser_get_precedence(char* op);

// Tokens
Token* Parser_current(Parser* p);
int Parser_get_op(char* value);