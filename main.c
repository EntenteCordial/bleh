#include <stdio.h>
#include "Object.c"

int main(){

	Object o1, o2, o3;
	Integer_create(&o1, 10);
	String_create(&o2, "hello");
	String_create(&o3, "goodbye");
	Object_set_dict(&o1, &o2, &o3);
	printf("hello = %s\n", Object_get_dict(&o1, &o2)->value.as_string);
	
	Object o4, o5;
	String_create(&o4, "wow");
	String_create(&o5, "great moves");
	Object_set_dict(&o1, &o4, &o5);
	printf("wow = %s\n", Object_get_dict(&o1, &o4)->value.as_string);
	
	return 0;
}