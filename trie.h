#ifndef trie_h
#define trie_h

#define NUM_LETTERS ((int)26)

typedef enum {false=0, true=1} boolean;

typedef struct node {
	boolean isLeaf;
	char letter;
	long unsigned int count;
	struct node* children[NUM_LETTERS];
} node;


struct node* new_node();
void insert(node* head, char* str);
boolean search (node* head, char* str);
boolean have_children (node* n);
boolean my_delete (node **n, char* str); 

#endif
