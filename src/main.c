#include <stdio.h>
#include <string.h>

#include "input.h"
#include "helpOpener.h"
#include "typeError.h"
#include "trig.h"

#define BUFFERSIZE 255

int main()	{
	
	printf("TRIG: the trigonometric calculator\n");
	printf("Please Input Request (h-help, q-quit): ");
	
	char userInput[BUFFERSIZE];
	// get an input
	strcpy(userInput, input());
	
	// keep getting an input until user inputs q
	while ('q' != userInput[0])	{
		
		unsigned int i, counter;
		counter = 1;
		
		// count how many inputs there were
		for (i = 0; i < strlen(userInput); ++i)	{
			
			// inputs are separated with white spaces
			if (' ' == userInput[i])	{
				
				++counter;
			}
		}
		
		// check if it is a legal input
		int error;
		char type[BUFFERSIZE], startString[BUFFERSIZE], endString[BUFFERSIZE], rowString[BUFFERSIZE];
		error = 0;
		
		// 1 input, and the input is either h or q if input is q, stops looping
		if (1 == counter && ('h' == userInput[0] || 'q' == userInput[0]))	{
			
			// display help message
			helpOpener();
		}
		else if (3 == counter)	{
			
			sscanf(userInput, "%s %s %s", startString, endString, rowString);
			
			// all functions with the base of degrees are operated
			strcpy(type, "sctd");
			
			// no alphabets allowed in inputs
			error = error + typeError(startString, counter, 1) + typeError(endString, counter, 2) + typeError(rowString, counter, 3);
		}
		else if (4 == counter)	{
			
			sscanf(userInput, "%s %s %s %s", type, startString, endString, rowString);
			error = error + typeError(type, counter, 1) + typeError(startString, counter, 2) + typeError(endString, counter, 3) + typeError(rowString, counter, 4);
		}
		else	{
			
			++error;
		}
		
		// only do the trig function if there are no errors and only when there are appropriate inputs
		if (0 == error && (3 == counter || 4 == counter))	{
			
			trig(type, startString, endString, rowString);
			// get new input, until you enter 'q' to quit
			strcpy(userInput, input());
		}
		else if (0 == error && 1 == counter && 'h' == userInput[0])	{
			
			// get new input, until you enter 'q' to quit
			strcpy(userInput, input());
		}
		else	{
			
			printf("Illegal Input!\n");
			// get new input, your input was invalid
			strcpy(userInput, input());
		}
	}
	
	return 0;
}
