#include <stdio.h>
#include "graph.h"
#include "periodic.h"

int main(int argc, char* argv[])
{
	FILE *front;
	front = fopen(argv[1],"r");
	if (!front)
	{
		printf("Incorrect file name entered");
		return 0;
	}
	int frame = get_frame_size(front);
	fclose(front);

}
