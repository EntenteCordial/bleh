// http://stackoverflow.com/questions/1485505/representing-dynamic-typing-in-c
#include <stdbool.h>
#define INITIAL_CAPACITY 2
#define OBJECT_TYPE 0
#define INTEGER_TYPE 1
#define STRING_TYPE 2

typedef union {
	int as_int;
	char* as_string;
	void* as_ptr;
} Value;

struct Object {
	
	int type;
	Value value;
	
	struct Object** keys;
	struct Object** values;
	size_t length;
	size_t capacity;
	
};
struct Object;
typedef struct Object Object;

void Object_create(Object* o);
void Object_destroy(Object* o);
void* Object_get(Object* o);
bool Object_compare(Object* o1, Object* o2);
void Object_create_dict(Object* o);

Object* Object_get_dict(Object* o, Object* key);
void Object_set_dict(Object* o, Object* key, Object* value);

void Integer_create(Object* o, int value);
void String_create(Object* o, char* value);