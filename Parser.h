#include "Tokeniser.c"

typedef struct {
	
	Token** tokens;
	size_t position;
	size_t end_position;
	
} Parser;

void Parser_create(Parser* p, Token** tokens);
void Parser_destroy(Parser* p);

void Parser_parse(Parser* p);
Token* Parser_current(Parser* p);