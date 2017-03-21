#include <stdio.h>
#include "Object.c"

int main(){

	Object o;
	Object o1, o2;
	
	Object_create(&o);
	Integer_create(&o1, 10);
	String_create(&o2, "hello");
	Object_set_dict(&o,&o1,&o2);
	printf("Dictionary size %i/%i\n", o.length, o.capacity);
	printf("Dictionary value 10: %s", Object_get_dict(&o,&o1)->value.as_string);
	
	
	printf("\n");
	Object o3, o4;
	Integer_create(&o3, 20);
	String_create(&o4, "hello");
	Object_set_dict(&o,&o3,&o4);
	printf("Dictionary size %i/%i\n", o.length, o.capacity);
	printf("Dictionary value 20: %s", Object_get_dict(&o,&o3)->value.as_string);
	
	printf("\n");
	Object o5, o6;
	Integer_create(&o5, 30);
	String_create(&o6, "hello");
	Object_set_dict(&o,&o5,&o6);
	printf("Dictionary size %i/%i\n", o.length, o.capacity);
	printf("Dictionary value 30: %s", Object_get_dict(&o,&o5)->value.as_string);
	
	printf("\n");
	
	Object_destroy(&o);
	Object_destroy(&o1);
	Object_destroy(&o2);
	Object_destroy(&o3);
	Object_destroy(&o4);
	Object_destroy(&o5);
	Object_destroy(&o6);
	
	return 0;
}