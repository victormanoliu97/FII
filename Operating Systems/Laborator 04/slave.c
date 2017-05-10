#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int result  = 0;
	
	if(argc < 4)
	{
		exit(-1);
	}

	int operand1 = atoi(argv[1]);

	int operand2 = atoi(argv[2]);

	if(argv[3][0] == '+')
	{
		result = operand1 + operand2;
	}
	else 
	{
		result = operand1 - operand2;
	}

	exit(result);
}