#include <stdio.h>
#include <string.h>
#include <math.h>

void trig(char typesToDo, double start, double end, int interRows)	{
	
	int i, doSin, doCos, doTan, deg, rad;
	doSin = 0;
	doCos = 0;
	doTan = 0;
	deg = 0;
	rad = 0;
	
	if (0 == strlen(typesToDo))	{
		
		++doSin;
		++doCos;
		++doTan;
	}
	else	{
		
		for (i = 0; i < strlen(typesToDo); ++i)	{
			
			if (0 == strcmp("s", typesToDo[i]))	{
				
				++doSin;
			}
			else if (0 == strcmp("c", typesToDo[i]))	{
				
				++doCos;
			}
			else if (0 == strcmp("t", typesToDo[i]))	{
				
				++doTan;
			}
			else if (0 == strcmp("r", typesToDo[i]))	{
				
				++rad;
			}
		}
	}
	
	deg = (0 == rad) ? 1: 0;
	
	int degrees[interRows + 2], radians[interRows + 2], sine[interRows + 2], cosine[interRows + 2], tangent[interRows + 2];
	double initial, increment;
	initial = start;
	increment = (end - start) / (interRows + 1);
	
	if (1 == deg)	{
		
		for (i = 0; i < interRows + 2; ++i)	{
			
			degrees[i] = initial;
			initial += increment;
		}
	}
	else	{
		
		for (i = 0; i < interRows + 2; ++i)	{
			
			radians[i] = initial;
			initial += increment;
		}
	}
}
