#define KEYWORD_TOKEN 0
#define STRING_TOKEN 1
#define INTEGER_TOKEN 2
#define IDENTIFIER_TOKEN 3
#define OPERATOR_TOKEN 3

typedef struct {
	
	int type;
	char* value;
	
} Token;

typedef struct {

	size_t position;
	size_t end_position;
	char* value;
	
	Token** tokens;
	int length;

} Tokeniser;

void Token_create(Token* t, int type, char* value);

void Tokeniser_create(Tokeniser* t, char* value);
void Tokeniser_destroy(Tokeniser* t);

void Tokeniser_tokenise(Tokeniser* t);
Token* Tokeniser_tokenise_operator(Tokeniser* t);
Token* Tokeniser_tokenise_identifier(Tokeniser* t);
Token* Tokeniser_tokenise_string(Tokeniser* t);
Token* Tokeniser_tokenise_integer(Tokeniser* t);

void Tokeniser_add(Tokeniser* t, Token* tok);

char Tokeniser_current(Tokeniser* t);
char Tokeniser_next(Tokeniser* t);