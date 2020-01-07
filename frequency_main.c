#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frequency.c"

int main()
{
	char* str;
	node* head = new_node();
	scanf(" %s",&str);
	insert(head, str);
	printf("%d %ld", search(head, str), head->count);
	
}
