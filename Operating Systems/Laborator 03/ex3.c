#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 10

int main()
{
	for(int i=0; i<N; i++)
	{
		pid_t child_pid = fork();

		if(child_pid == -1)
		{
			perror("Fork error\n");
			exit(2);
		}
		else if(child_pid == 0)
		{
			printf("Process %d\n", getpid() );

			return 0;
		}
	}

	return 0;
}