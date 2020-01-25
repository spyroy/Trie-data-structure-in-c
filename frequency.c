#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "trie.h"


trie* init()
{
    trie* h=(trie*)malloc(sizeof(trie));
    h->head=new_node(0);
    return h;
}

struct node* new_node(char l)
{
	node* n =(node*) malloc(sizeof(node));
	n->isLeaf = false;
	n->letter = l;
	int i;
	for(i=0; i<NUM_LETTERS; i++)
	{
		n->children[i] = NULL;
	}
	n->count = 0;
	n->isLeaf = false;
	return n;
}

void insert (trie* t, char* str)
{
	node* n = t->head;
	while(*str)
	{
		int current = *str-'a';
		if(n->children[current] == NULL)
		{	
			n->children[current] = new_node((char)*str);
		}
		n = n->children[current];
		str++;
	}
	n->count++;
	n->isLeaf = true;
	
}

//search for specific word (not used after all).
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

//used for my_delete to determine if node has children
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

// used to delete a word from the tree using free()
// eventually used free_n to free all nodes instead of all words.
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

void print(trie* h, int size)
{
	char str [size];
    	print_recursive(h->head,str,0);
}

void print_recursive(node* n, char* str, int i)
{
	if(n == NULL)
		return;
	if(n->isLeaf==true)
   	{
        	str[i]='\0';
        	printf("%s\t%ld\n",str, n->count);
    	}
	int j;
    	for(j=0; j<NUM_LETTERS; j++)
    	{
        	if(n->children[j]!=NULL) 
        	{    
        		str[i]=j+'a';
        		print_recursive(n->children[j],str,i+1);
        	}
    	}
}

void printR(trie* h, int size)
{
	char str [size];
    	print_recursiveR(h->head,str,0);
}

void print_recursiveR(node* n, char* str, int i)
{
	if(n == NULL)
		return;
	int j;
	for(j=NUM_LETTERS-1; j>=0; j--)
	{
		if(n->children[j] != NULL)
		{
			str[i]=j+'a';
        		print_recursiveR(n->children[j],str,i+1);
		}
	}
	if(n->isLeaf==true)
   	{
        	str[i]='\0';
        	printf("%s\t%ld\n",str, n->count);
    	}
}

void free_t(trie* t)
{
   if(t!=NULL)
   {
     free_n(t->head); 
   } 
   free(t); 
}

void free_n(node* n)
{
	int i;
    	for(i=NUM_LETTERS-1; i>=0; i--)  
    	{
        	if(n->children[i]!=NULL)
        	{
        		free_n(n->children[i]);
        	}
    	}
    	if(n!=NULL)
    	{
    		free(n);
    	}
}


//char* getWord(const char *str, int size)
//{
//	while ( ( str += strspn(str, " \t") ) != '\0' && size-- )
//    	{
//        	str += strcspn(str, " \t");
//    	}
//    	return *str ? (char *)str : (char *)0;
//}

	
	

