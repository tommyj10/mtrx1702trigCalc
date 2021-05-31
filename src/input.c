#include "input.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 255

char * input()	{
	
	// initialize an empty string
	static char prompt[BUFFERSIZE] = "";
	
	fgets(prompt, BUFFERSIZE, stdin);
	
	return prompt;
}
