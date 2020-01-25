#include "frequency.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define WORD 60

int main(int argc, char* argv[])
{
		
	
	trie* t = init();
	char str[WORD];
	if (stdin)
	{
		while (fscanf(stdin, "%59s", str) == 1)
		{
			int i;
			for(i = 0; str[i]; i++)
			{
  				str[i] = tolower(str[i]);
				if(str[i] > 122 || str[i] < 97)
					str[i] = '\0';
			}
			insert(t,str);
		}
		fclose(stdin);
	}
	if(argc == 2 && strcmp(argv[1]," r"))
	{
		printR(t,0);
	}
	else
		print(t,0);
	free_t(t); 
	return 0;	
    
}
