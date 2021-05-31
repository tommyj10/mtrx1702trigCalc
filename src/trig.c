#include "trig.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFERSIZE 255
#define PI 3.14159265

void trig(char * type, char * startString, char * endString, char * rowString)	{
	
	double start, end;
	int interRows;
	// convert all strings to appropriate types of variables
	start = atof(startString);
	end = atof(endString);
	interRows = atoi(rowString);
	
	// determine what to do
	int doSin, doCos, doTan, degrees, radians;
	doSin = 0;
	doCos = 0;
	doTan = 0;
	degrees = 0;
	radians = 0;
	unsigned int i;
	for (i = 0; i < strlen(type); ++i)	{
		
		// sine
		if ('s' == type[i])	{
			
			++doSin;
		}
		// cosine
		else if ('c' == type[i])	{
			
			++doCos;
		}
		// tangent
		else if ('t' == type[i])	{
			
			++doTan;
		}
		// degrees
		else if ('d' == type[i])	{
			
			++degrees;
		}
		// already filtered out before this function, so the only left possible element is r
		else	{
			
			++radians;
		}
	}
	// if no 'd' or 'r', then we do it in degrees by default
	degrees = (0 == degrees && 0 == radians) ? 1: degrees;
	
	// check if needed to do everything
	if (doSin == doCos && doCos == doTan && 0 == doSin)	{
		
		++doSin;
		++doCos;
		++doTan;
	}
	
	// initialize the initial values and increments
	double initial, increment, deg[interRows + 2], rad[interRows + 2];
	initial = start;
	increment = (end - start)/(interRows + 1);
	
	// set default values for angles
	for (i = 0; i < interRows + 2; ++i)	{
		
		if (0 != degrees)	{
			
			// degrees
			deg[i] = initial;
		}
		else	{
			
			// radians
			rad[i] = initial;
		}
		
		// next value
		initial += increment;
	}
	
	for (i = 0; i <interRows + 2; ++i)	{
		
		if (0 == degrees)	{
			
			// convert to degrees
			deg[i] = rad[i] * 180 / PI;
		}
		else	{
			
			// to radians
			rad[i] = deg[i] * PI / 180;
		}
	}
	
	double sine[interRows + 2], cosine[interRows + 2], tangent[interRows + 2];
	
	for (i = 0; i < interRows + 2; ++i)	{
		
		// process calculations
		sine[i] = sin(rad[i]);
		cosine[i] = cos(rad[i]);
		tangent[i] = sine[i] / cosine[i];
	}
	
	for (i = 0; i <= interRows + 2; ++i)	{
		
		// first row
		if (0 == i)	{
			
			// display degrees and radians
			printf("   Degrees   Radians");
			
			// sine
			if (0 < doSin)	{
				
				printf("       Sin");
			}
			// cosine
			if (0 < doCos)	{
				
				printf("       Cos");
			}
			// tangent
			if (0 < doTan)	{
				
				printf("       Tan");
			}
			// new line
			printf("\n");
		}
		else	{
			
			// degrees and radians
			printf("%10.3lf%10.3lf", deg[i - 1], rad[i - 1]);
			
			if (0 < doSin)	{
				
				printf("%10.3lf", sine[i - 1]);
			}
			// cosine
			if (0 < doCos)	{
				
				printf("%10.3lf", cosine[i - 1]);
			}
			// tangent
			if (0 < doTan)	{
				
				printf("%10.3lf", tangent[i - 1]);
			}
			// new line
			printf("\n");
		}
	}
}
