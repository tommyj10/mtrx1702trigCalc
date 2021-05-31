#include "degreesOrRadians.h"

#include <stdio.h>
#include <string.h>

char * degreesOrRadians(char * string)	{
	
	// check if degrees or radians
	int degrees, radians;
	degrees = 0;
	radians = 0;
	
	// go through all elements and find d or r
	unsigned int i;
	for (i = 0; i < strlen(string); ++i)	{
		
		// degrees
		if ('d' == string[i])	{
			
			++degrees;
		}
		else if ('r' == string[i])	{
			
			++radians;
		}
	}
	
	char result[1];
	
	if (degrees == radians && 0 == degrees)	{
		
		// degrees
		strcpy(result, "d");
	}
	// means degrees and radians are not equal, but degrees is 0, so radians
	else if (0 == degrees)	{
		
		strcpy(result, "r");
	}
	else	{
		
		strcpy(result, "d");
	}
	
	return result;
}
