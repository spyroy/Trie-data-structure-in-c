#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

struct node* new_node()
{
	node* n =(node*) malloc(sizeof(node));
	n->isLeaf = false;
	int i;
	for(i=0; i<NUM_LETTERS; i++)
	{
		n->children[i] = NULL;
	}
	return n;
}

void insert (node* head, char* str)
{
	node* n = head;
	int current = *str-'a';
	while(*str)
	{
		if(n->children[current] == NULL)
		{	
			n->children[current] = new_node();
		}
		n = n->children[current];
		str++;
	}
	n->count++;
	n->isLeaf = true;
	
}

boolean search (node* head, char* str)
{
	if(head == NULL)
	{
		return false;
	}
	int current = *str-'a';
	node* n = head;
	while(*str)
	{
		n = n->children[current];
		if(n == NULL)
		{
			return false;
		}
		str++;
	}
	return n->isLeaf;
}

boolean have_children (node* n)
{
	int i;
	for(i = 0; i<NUM_LETTERS; i++)
	{
		if(n->children[i])
		{
				return true;
		}
	}
	return false;
}

boolean my_delete (node **n, char* str)
{
	if(*n == NULL)
	{
		return false;
	}
	int current = *str-'a';
	if(*str)
	{
		if(*n != NULL && (*n)->children[current] != NULL && my_delete(&((*n)->children[current]),str+1) && (*n)->isLeaf == false)
		{
			if(!have_children(*n))
			{
				free(*n);
				(*n) = NULL;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	if(*str == '\0' && (*n)->isLeaf == true)
	{
		if(!have_children(*n))
		{
			free(*n);
			(*n) = NULL;
			return true;
		}
		else
		{
			(*n)->isLeaf = false;
			return false;
		}
	}
	return false;
}
	

