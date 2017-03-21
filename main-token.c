#include <stdio.h>
#include "Tokeniser.c"

int main(){
	char* value = "if 'hello' == 1 {";
	Tokeniser tokeniser;
	Tokeniser_create(&tokeniser, value);
	
	/*
	Token tok;
	Token_create(&tok, STRING_TOKEN, "hello world");
	Tokeniser_add(&tokeniser, &tok);
	//printf("%s", tokeniser.tokens[0]->value);
	*/
	
	Tokeniser_tokenise(&tokeniser);
	
	return 0;
	
};