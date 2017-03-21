#include <stdio.h>
#include "AST.c"

int main(){
	
	printf("Value test\n");
	
	printf("Identifier test:\n");
	ValueTree val1;
	IdentifierTree_create(&val1, "hello");
	printf("%s\n", ValueTree_get(&val1));
	
	printf("String test:\n");
	ValueTree val2;
	StringTree_create(&val2, "holy cow");
	printf("%s\n", ValueTree_get(&val2));
	
	printf("Integer test:\n");
	ValueTree val3;
	IntegerTree_create(&val3, 120);
	printf("%i\n", ValueTree_get(&val3));
	
	printf("\n");
	
	printf("Expression Tree test \n");
	ExpressionTree expr;
	
	ExpressionValueTree left;
	ExpressionValueTree_wrap_value(&left, &val1);
	printf("Left side: %s\n", ExpressionValueTree_get(&left));
	
	ExpressionValueTree right;
	ExpressionValueTree_wrap_value(&right, &val2);
	printf("Right side: %s\n", ExpressionValueTree_get(&right));
	
	ExpressionTree_create(&expr, &left, &right, PLUS_OP);
	
	printf("Expression tree created!\n");
	printf("%s %c %s\n",
	ExpressionValueTree_get(expr.left),
	(expr.op == PLUS_OP ? '+' : '?'),
	ExpressionValueTree_get(expr.right));
	
	CommandTree* commands;
	CommandTree commandTree;
	
	printf("\n");
	
	printf("Definition command test \n");
	
	ValueTree lhsValue;
	IdentifierTree_create(&lhsValue, "Hello");
	ValueTree rhsValue;
	IdentifierTree_create(&rhsValue, "NEIN");
	ExpressionValueTree rhs;
	ExpressionValueTree_wrap_value(&rhs, &rhsValue);
	
	DefinitionTree_create(&commandTree, &lhsValue, &rhs);
	printf("%s = %s\n",
	ValueTree_get(((DefinitionTree*)CommandTree_get(&commandTree))->left),
	ExpressionValueTree_get(((DefinitionTree*)CommandTree_get(&commandTree))->right));
	CommandTree_destroy(&commandTree);
	
	printf("\n");
	
	printf("If command test \n");
	IfTree_create(&commandTree, &expr, &commands);
	printf("if %s %c %s {}\n",
	ExpressionValueTree_get(((IfTree*)CommandTree_get(&commandTree))->expression->left),
	(commandTree.command->ifTree->expression->op == PLUS_OP ? '+' : '?'),
	ExpressionValueTree_get(((IfTree*)CommandTree_get(&commandTree))->expression->right));
	CommandTree_destroy(&commandTree);
	
	return 0;
	
};