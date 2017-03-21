#include <string.h>
#include <stdlib.h>
#include "Object.h"

// Objects
void Object_create(Object* o){
	o->type = OBJECT_TYPE;
	Object_create_dict(o);
};

void Object_destroy(Object* o){
	free(o->keys);
	free(o->values);
};

void* Object_get(Object* o){
	if(o->type == INTEGER_TYPE){
		return (void*)o->value.as_int;
	} else if (o->type == STRING_TYPE) {
		return (void*)o->value.as_string;
	} else {
		return NULL;
	}
};

bool Object_compare(Object* o1, Object* o2){
	if(o1->type != o2->type){
		return false;
	} else {
		if(o1->type == OBJECT_TYPE) {
			return false; // TODO define behavior
		} else if (o1->type == INTEGER_TYPE) {
			return o1->value.as_int == o2->value.as_int;
		} else if (o1->type == STRING_TYPE) {
			return strcmp(o1->value.as_string, o2->value.as_string) == 0;
		} else {
			return false;
		}
	}
};

// Object dictionary
void Object_create_dict(Object* o){
	o->length = 0;
	o->capacity = INITIAL_CAPACITY;
	o->keys = malloc(sizeof(Object) * o->capacity);
	o->values = malloc(sizeof(Object) * o->capacity);
};

Object* Object_get_dict(Object* o, Object* key){
	int i;
	for(i = 0; i < o->length; i++) {
		if(Object_compare(o->keys[i], key)) {
			return o->values[i];
		}
	}
	return NULL;
};

void Object_set_dict(Object* o, Object* key, Object* value){
	if(o->length == o->capacity) {
		o->capacity *= 2;
		void* tmp_keys = realloc(o->keys, sizeof(Object) * o->capacity);
		void* tmp_values = realloc(o->values, sizeof(Object) * o->capacity);
		if (tmp_keys == NULL || tmp_values == NULL) {
			return;
		} else {
			o->keys = (Object*)tmp_keys;
			o->values = (Object*)tmp_values;
		}
	}
	o->keys[o->length] = key;
	o->values[o->length] = value;
	o->length++;
};

// Integer
void Integer_create(Object* o, int value){
	o->type = INTEGER_TYPE;
	o->value.as_int = value;
	Object_create_dict(o);
};

// String
void String_create(Object* o, char* value){
	o->type = STRING_TYPE;
	o->value.as_string = value;
	Object_create_dict(o);
};