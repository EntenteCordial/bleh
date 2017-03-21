#include "Parser.h"

void Parser_create(Parser* p, Token** tokens){
	p->tokens = tokens;
	p->position = 0;
	p->end_position = sizeof(tokens) / sizeof(Token);
};

void Parser_parse(Parser* p){
	while(p->position < p->end_position){
		Token* current = Parser_current(p);
		if(current->type == OPERATOR_TOKEN)
	}
};

Token* Parser_current(Parser* p){
	if(p->position > p->end_position){
		return NULL; // TODO ERROR
	} else {
		return p->tokens[p->position];
	}
};