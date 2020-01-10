#include "frequency.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	trie* t = init();
	char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    characters = getline(&buffer,&bufsize,stdin);
	insert(t,characters);
	print(t,0);
	free_t(t);
    

    return(0);		
    
}
