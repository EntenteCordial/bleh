#include "AST.h"

// Value
void IdentifierTree_create(ValueTree* t, char* string){
	t->type = IDENTIFIER_TYPE;
	t->value.string = string;
};

void StringTree_create(ValueTree* t, char* string){
	t->type = STRING_TYPE;
	t->value.string = string;
};

void IntegerTree_create(ValueTree* t, int integer){
	t->type = INTEGER_TYPE;
	t->value.integer = integer;
};

void* ValueTree_get(ValueTree* t){
	if(t->type == IDENTIFIER_TYPE || t->type == STRING_TYPE) {
		return (void*)t->value.string;
	} else if (t->type == INTEGER_TYPE) {
		return (void*)t->value.integer;
	} else {
		return NULL;
	}
};

// Expression
void ExpressionTree_create(ExpressionTree* t, ExpressionValueTree* left, ExpressionValueTree* right, int op){
	t->left = left;
	t->right = right;
	t->op = op;
};

void ExpressionValueTree_wrap_value(ExpressionValueTree* t, ValueTree* value){
	t->value.value = value;
	t->type = VALUE_TYPE;
};

void ExpressionValueTree_wrap_expression(ExpressionValueTree* t, ExpressionTree* expr){
	t->value.expression = expr;
	t->type = EXPRESSION_TYPE;
};

void* ExpressionValueTree_get(ExpressionValueTree* t){
	if(t->type == VALUE_TYPE) {
		return ValueTree_get(t->value.value);
	} else {
		return (void*)t->value.expression;
	}
};

// Command Tree
void* CommandTree_get(CommandTree* t){
	if(t->type == IF_TREE) {
		return t->command->ifTree;
	} else if (t->type == DEFINITION_TREE) {
		return t->command->definitionTree;
	} else {
		return NULL;
	}
};

void CommandTree_destroy(CommandTree* t){
	free(t->command);
	//if(t->type == IF_TREE){
	//	free(t->command->ifTree);
	//}
};

// If Tree
void IfTree_create(CommandTree* t, ExpressionTree* expression, CommandTree** commands){
	t->type = IF_TREE;
	void* tmp_command = malloc(sizeof(expression) + sizeof(commands));
	void* tmp_ifTree = malloc(sizeof(expression) + sizeof(commands));
	if(tmp_command == NULL || tmp_ifTree == NULL) {
		// TODO ERROR
		return;
	} else {
		t->command = (CommandTree*)tmp_command;
		t->command->ifTree = (IfTree*)tmp_ifTree;
		t->command->ifTree->expression = expression;
		t->command->ifTree->commands = commands;
	}
};

// Definition Tree
void DefinitionTree_create(CommandTree* t, ValueTree* left, ExpressionValueTree* right){
	if(left->type != IDENTIFIER_TYPE) {
		// TODO ERROR
		return;
	}
	
	t->type = DEFINITION_TREE;
	void* tmp_command = malloc(sizeof(left) + sizeof(right));
	void* tmp_definitionTree = malloc(sizeof(left) + sizeof(right));
	if(tmp_command == NULL || tmp_definitionTree == NULL){
		// TODO ERROR
		return;
	} else {
		t->command = (CommandTree*)tmp_command;
		t->command->definitionTree = (DefinitionTree*)tmp_definitionTree;
		t->command->definitionTree->left = left;
		t->command->definitionTree->right = right;
	}
};