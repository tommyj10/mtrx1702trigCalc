#include "typeError.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int typeError(char * string, int inputQuantity, int order)	{
	
	int errorInput;
	errorInput = 0;
	
	// check if valid input
	if (3 == inputQuantity)	{
		
		unsigned int i;
		for (i = 0; i < strlen(string); ++i)	{
			
			// no alphabet is allowed in the inputs when there are only three inputs
			if (isalpha(string[i]))	{
				
				++errorInput;
			}
		}
	}
	// we only use this function for 2 occasions, when the input quantity is either 3 or 4
	else	{
		
		// we first take the first string, which indicate the types
		if (1 == order)	{
			
			// no letter errors yet
			unsigned int i, letterError, degrees, radians;
			letterError = 0;
			degrees = 0;
			radians = 0;
			
			for (i = 0; i < strlen(string); ++i)	{
				
				// assume there is an error in the letter, but if there isnt after the search, then reduce the value
				++letterError;
				if ('s' == string[i] || 'c' == string[i] || 't' == string[i] || 'd' == string[i] || 'r' == string[i])	{
					
					--letterError;
					
					// process degrees
					if ('d' == string[i])	{
						
						++degrees;
					}
					else if ('r' == string[i])	{
						
						++radians;
					}
				}
			}
			
			// check if user input both d and r
			if (0 < degrees && 0 < radians)	{
				
				++letterError;
			}
			
			// add the number of errors in the letters to the total number of errors
			errorInput += letterError;
		}
		// only check for the 2nd and 3rd inputs
		else if (inputQuantity != order)	{
			
			// no errors in the floats yet
			unsigned int i, floatError;
			floatError = 0;
			
			for (i = 0; i < strlen(string); ++i)	{
				
				int dotError;
				dotError = 0;
				
				// dot points and numbers allowed
				if (isalnum(string[i]))	{
					
					// no alphabets
					if (isalpha(string[i]))	{
						
						++floatError;
					}
				}
				else if ('.' == string[i])	{
					
					++dotError;
				}
				// everything else are errors
				else	{
					
					++floatError;
				}
				
				// check if there are too many dot points
				if (2 <= dotError)	{
					
					++floatError;
				}
			}
			
			// add the number of errors in the floats to the total number of errors
			errorInput += floatError;
		}
	}
	
	// check for the last one
	if (inputQuantity == order)	{
		
		// no errors in the integer yet
		unsigned int i, intError;
		intError = 0;
		
		for (i = 0; i < strlen(string); ++i)	{
			
			// only decimal numbers are allowed
			if (isalnum(string[i]))	{
				
				// no alphabets
				if (isalpha(string[i]))	{
					
					++intError;
				}
			}
			else	{
				
				++intError;
			}
		}
		
		// add the number of errors in the integer to the total number of errors
		errorInput += intError;
	}
	
	return errorInput;
}
