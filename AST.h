#define IDENTIFIER_TYPE 0
#define STRING_TYPE 1
#define INTEGER_TYPE 2

#define EXPRESSION_TYPE 0
#define VALUE_TYPE 1

#define DEFINITION_TREE 0
#define CALL_TREE 1
#define FUNCTION_TREE 2
#define ARGUMENT_TREE 3
#define IF_TREE 4
#define WHILE_TREE 5

#define PLUS_OP 0
#define MINUS_OP 1
#define MULT_OP 2
#define DIV_OP 3

// Value
typedef struct {
	
	union {
		int integer;
		char* string;
	} value;
	int type;
	
} ValueTree;

void IdentifierTree_create(ValueTree* t, char* string);
void StringTree_create(ValueTree* t, char* string);
void IntegerTree_create(ValueTree* t, int integer);
void* ValueTree_get(ValueTree* t);

// Expression
struct ExpressionTree;
struct ExpressionValueTree {

	union {
		
		ValueTree* value;
		struct ExpressionTree* expression;
		
	} value;
	int type;

};
typedef struct ExpressionValueTree ExpressionValueTree;
struct ExpressionTree {
	
	ExpressionValueTree* left;
	ExpressionValueTree* right;
	int op;
	
};
struct ExpressionTree;
typedef struct ExpressionTree ExpressionTree;

void ExpressionTree_create(ExpressionTree* t, ExpressionValueTree* left, ExpressionValueTree* right, int op);

void ExpressionValueTree_wrap_value(ExpressionValueTree* t, ValueTree* value);
void ExpressionValueTree_wrap_expression(ExpressionValueTree* t, ExpressionTree* expr);
void* ExpressionValueTree_get(ExpressionValueTree* t);

// Commands
union CommandTreeUnion;
struct CommandTree {
	union CommandTreeUnion* command;
	int type;
};
typedef struct CommandTree CommandTree;
void* CommandTree_get(CommandTree* t);
void CommandTree_destroy(CommandTree* t);

// If Tree
typedef struct {
	ExpressionTree* expression;
	CommandTree** commands;
} IfTree;
void IfTree_create(CommandTree* t, ExpressionTree* expression, CommandTree** commands);


// Definition Tree
typedef struct {
	ValueTree* left;
	ExpressionValueTree* right;
} DefinitionTree;
void DefinitionTree_create(CommandTree* t, ValueTree* left, ExpressionValueTree* right);

// Define command union
union CommandTreeUnion {
	IfTree* ifTree;
	DefinitionTree* definitionTree;
};