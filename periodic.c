#include "periodic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

int lcmf(int a, int b)
{
	return (a*b/gcd(a, b));
}

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int get_frame_size(FILE* periodic)
{
	char cont[1000];
	int maxm_exec = 0;
	int minm_f = 1000000;
	int lcm = 1;
	int possible_frames[50] = {0};
	while (fgets(cont, 1000, periodic))
	{
		char* temp = strdup(cont);
		int curr = atoi(getfield(temp, 2));
		if (curr > maxm_exec)
		{
			maxm_exec = curr; //find minimum frame size by E1
		}
		int period = atoi(getfield(temp, 1));
		lcm = lcmf(period, lcm);
		int dead = atoi(getfield(temp, 3));
		for (int i=1; i <= dead; i++)
		{
			int comp = 2*i - gcd(period, i);
			if (comp <= dead)
			{
				if (comp < minm_f)
				{
					minm_f = comp; //find maximum frame size by E3
				}
			}
		}
		free(temp);
	}
	int point = 0;
	for (int i=maxm_exec; i <= minm_f; i++)
	{
		if (lcm%i == 0)
		{
			possible_frames[point++] = i; //store possible frame lengths according to E2
		}
	}

}
