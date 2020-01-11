#include "frequency_r.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define WORD 30

int main(int argc, char* argv[])
{
	trie* t = init();
	char str[WORD];
	if (stdin)
	{
		while (fscanf(stdin, "%49s", str) == 1)
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
	print(t,0);
	free_t(t); 
	return 0;  
}
