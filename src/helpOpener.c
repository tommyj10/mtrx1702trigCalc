#include "helpOpener.h"
#include <stdio.h>
#include <string.h>

void helpOpener()	{
	
	FILE * help = fopen("helpMessage.txt", "r");
	
	char message[255];		
	int i;
	
	for (i = 1; fgets(message, sizeof(message), help) != NULL; ++i)	{			
		
		printf("%s", message);
	}
			
	fclose(help);
}
