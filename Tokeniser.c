#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "Tokeniser.h"

void Tokeniser_create(Tokeniser* t, char* value){
	t->position = 0;
	t->end_position = strlen(value);
	t->value = strdup(value);
	
	//printf("value: %s\n", t->value);
	//printf("\n");
	
	t->tokens = (Token**)malloc(sizeof(Token**));
	t->length = 0;
	
	printf("Initialized\n");
};

void Tokeniser_destroy(Tokeniser* t){

};

void Tokeniser_add(Tokeniser* t, Token* tok){
	void* tmp_tokens = realloc(t->tokens, (t->length + 1)*sizeof(Token**));
	if (tmp_tokens == NULL) {
		printf("NULLPO"); // TODO error
		return;
	} else {
		t->tokens = (Token**)tmp_tokens;
		t->tokens[t->length] = tok;
		//t->tokens[t->length]->v = tok->value;
		t->length++;
	}
};

void Tokeniser_tokenise(Tokeniser* t){
	//putchar(t->value[t->position]);
	char current;
	while(t->position < t->end_position){
		current = Tokeniser_current(t);
		
		if (isspace(current)) {
			t->position++;
			continue;
		}
		
		Token* token;
		if(current == '"' || current == '\''){ // string
			token = Tokeniser_tokenise_string(t);
		} else if (
			current == '(' || current == ')' ||
			current == '{' || current == '}' ||
			current == '+' || current == '-' ||
			current == '*' || current == '/' ||
			current == '='
		) { // operator
			token = Tokeniser_tokenise_operator(t);
		} else if (isdigit(current)) {// number
			token = Tokeniser_tokenise_integer(t);
		} else if (isalpha(current)) { // identifier
			token = Tokeniser_tokenise_identifier(t);
		} else {
			printf("SyntaxError: unexpected %c\n", current); // TODO error
			return;
		}
		
		Tokeniser_add(t, token);
	}
};

Token* Tokeniser_tokenise_operator(Tokeniser* t){
	char current = Tokeniser_current(t);
	char next = Tokeniser_next(t);
	char* string;
	
	if( (current == '=' && next == '=') ) {
		string = malloc(sizeof(char) * 2);
		string[0] = current;
		string[1] = next;
		t->position += 2;
	} else {
		string = malloc(sizeof(char));
		*string = current;
		t->position++;
	}
	
	printf("OPERATOR %s\n", string);
	Token* token = (Token*)malloc(sizeof(int) + sizeof(string));
	Token_create(token, OPERATOR_TOKEN, string);
	return token;
};

Token* Tokeniser_tokenise_identifier(Tokeniser* t){
	char* string = malloc(sizeof(char));
	*string = Tokeniser_current(t);
	t->position++;
	
	char current;
	size_t string_len = 1;
	while(t->position < t->end_position) {
		current = Tokeniser_current(t);
		if(isalnum(current)) {
			string = (char*)realloc(string, string_len*sizeof(char));
			string[string_len] = current;
			string_len++;
			t->position++;
		} else {
			break;
		}
	}
	
	printf("IDENTIFIER %s\n", string);
	
	Token* token = (Token*)malloc(sizeof(int) + sizeof(string));
	Token_create(token, IDENTIFIER_TOKEN, string);
	return token;
};

Token* Tokeniser_tokenise_string(Tokeniser* t){
	char begin = Tokeniser_current(t);
	t->position++;
	
	char* string = (char*)malloc(sizeof(char));
	*string = Tokeniser_current(t);
	t->position++;
	
	size_t string_len = 0;
	
	char current;
	while(t->position < t->end_position) {
		current = Tokeniser_current(t);
		if(current == begin) {
			break;
		} else {
			string = (char*)realloc(string, (string_len + 1)*sizeof(char));
			string[string_len + 1] = current;
			string_len++;
		}
		t->position++;
	}
	
	//putchar(Tokeniser_current(t));
	if(Tokeniser_current(t) != begin) {
		printf("SyntaxError: expected %c\n", begin); // TODO error
		//return NULL;
	}
	t->position++;
	
	printf("STRING %s\n", string);
	
	Token* token = (Token*) malloc(sizeof(int) + sizeof(string));
	Token_create(token, STRING_TOKEN, string);
	return token;
};

Token* Tokeniser_tokenise_integer(Tokeniser* t){
	char* string = malloc(sizeof(char));
	*string = Tokeniser_current(t);
	t->position++;
	
	char current;
	size_t string_len = 1;
	while(t->position < t->end_position) {
		current = Tokeniser_current(t);
		if(isdigit(current)) {
			string = (char*)realloc(string, string_len*sizeof(char));
			string[string_len] = current;
			string_len++;
			t->position++;
		} else {
			break;
		}
	}
	
	printf("INTEGER %s\n", string);
	
	Token* token = (Token*) malloc(sizeof(int) + sizeof(string));
	Token_create(token, IDENTIFIER_TOKEN, string);
	return token;
};

char Tokeniser_current(Tokeniser* t){
	if(t->position > t->end_position){
		printf("Overflow"); // TODO error
		return '\0';
	} else {
		return t->value[t->position];
	}
};

char Tokeniser_next(Tokeniser* t){
	if(t->position + 1 > t->end_position) {
		return '\0';
	} else {
		return t->value[t->position];
	}
};

// Tokens
void Token_create(Token* t, int type, char* value){
	t->type = type;
	t->value = value;
};