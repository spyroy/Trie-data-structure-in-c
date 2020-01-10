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

typedef struct trie {
	node* head;
} trie;

struct node* new_node(char l);
trie* init();
void insert(trie* t, char* str);
boolean search (node* head, char* str);
boolean have_children (node* n);
boolean my_delete (node **n, char* str);
void print(trie* h, int size);
void print_recursive(node* n, char* str, int i);
char* getWord(const char *str, int size);
void free_t(trie* t);
void free_n(node* n);
 

#endif
