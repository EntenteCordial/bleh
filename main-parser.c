#include <stdio.h>
#include "Parser.c"

int main(){
	Tokeniser tokeniser;
	Tokeniser_create(&tokeniser, "'hello'");
	Tokeniser_tokenise(&tokeniser);
	
	Token** tokens = tokeniser.tokens;
	
	Parser parser;
	Parser_create(&parser, &tokens);
	
	printf("\n");
	
	printf("Expression parse test: \n");
	ExpressionValueTree valueTree = Parser_parse_value(&parser);
	printf("%s\n", ExpressionValueTree_get(&valueTree));
	
	return 0;
};