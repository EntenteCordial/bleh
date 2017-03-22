#include <string.h>
#include <stdlib.h>
#include "Object.h"

// Object creation
void Object_create(Object* o){
	o->type = OBJECT_TYPE;
	o->first = NULL;
	o->last = NULL;
};

// Integer
void Integer_create(Object* o, int value){
	o->type = INTEGER_TYPE;
	o->value.as_int = value;
	o->first = NULL;
	o->last = NULL;
};

// String
void String_create(Object* o, char* value){
	o->type = STRING_TYPE;
	o->value.as_string = value;
	o->first = NULL;
	o->last = NULL;
};

// Object prototype
void Object_create_dict(Object* o){
	o->first = NULL;
	o->last = NULL;
};

void Object_destroy(Object* o){
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
void ObjectPair_create(ObjectPair* o, Object* key, Object* value){
	o->key = key;
	o->value = value;
	o->next = NULL;
};

Object* Object_get_dict(Object* o, Object* key){
	ObjectPair* current = o->last;
	//printf("%s", current->value->value.as_string);
	//return o->last->value;
	while(current != NULL){
		if(Object_compare(current->key, key)){
			return current->value;
		} else {
			current = current->next;
		}
	}
	return NULL;
};

void Object_set_dict(Object* o, Object* key, Object* value){
	ObjectPair* pair = (ObjectPair*)malloc(sizeof(ObjectPair));
	ObjectPair_create(pair, key, value);
	if(o->first == NULL){
		o->first = pair;
		o->last = pair;
	} else {
		o->last->next = pair;
		o->last = pair;
	}
	//printf("%s", o->last->value->value.as_string);
};