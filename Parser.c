#include <stdlib.h>
#include "Parser.h"
//#include "Tokeniser.c"

void Parser_create(Parser* p, Token*** tokens){
	p->tokens = *tokens;
	printf("Initialized parser\n");
	
	p->position = 0;
	p->end_position = sizeof(tokens) / sizeof(Token*);
	printf("end: %i\n", p->end_position);
};

void Parser_parse_program(Parser* p){
	while(p->position < p->end_position){
		Token* current = Parser_current(p);
	}
};

// Expressions
ExpressionValueTree Parser_parse_expression(Parser* p){
	ExpressionValueTree left = Parser_parse_value(p);
	
	Token* current = Parser_current(p);
	int op = Parser_get_op(current->value);
	
	ExpressionValueTree right = Parser_parse_value(p);
};

ExpressionValueTree Parser_parse_value(Parser* p){
	Token* current = Parser_current(p);
	
	printf("%s\n",p->tokens[0]->value);
	printf("position: %i/%i\n", p->position, p->end_position);
	
	ValueTree value;
	if(current->type == STRING_TOKEN) {
		printf("STRING TYPE\n");
		StringTree_create(&value, current->value);
	} else if (current->type == INTEGER_TOKEN) {
		IntegerTree_create(&value, atoi(current->value));
	} else if (current->type == IDENTIFIER_TOKEN) {
		IdentifierTree_create(&value, current->value);
	} else {
		printf("UNSPECIFIED TYPE");
		// TODO error
		//return NULL;
	}
	ExpressionValueTree expr;
	ExpressionValueTree_wrap_value(&expr, &value);
	p->position++;
	return expr;
};

// Commands
//CommandTree* Parser_parse_definition(Parser* p){};

//CommandTree* Parser_parse_if(Parser* p){};

// Tokens
Token* Parser_current(Parser* p){
	if(p->position > p->end_position){
		printf("OVERFLOW\n");
		return NULL; // TODO ERROR
	} else {
		//printf("CURRENT: %s\n", p->tokens[p->position]->value);
		return p->tokens[p->position];
	}
};

int Parser_get_op(char* value){
	if(strcmp(value, "+") == 0){
		return PLUS_OP;
	} else if(strcmp(value, "-") == 0){
		return MINUS_OP;
	} else if(strcmp(value, "*") == 0){
		return MULT_OP;
	} else if(strcmp(value, "/") == 0){
		return DIV_OP;
	} else {
		return -1;
	}
};