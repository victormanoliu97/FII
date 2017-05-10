#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define STORAGE_SIZE 30

int main(int argc, char const *argv[])
{
	
	int operand1;
	int operand2;

	char operator;

	int read_status = 0;

	do
	{
		printf("Introduceti 2 numere si un operator: \n");

		scanf("%d %d %c", &operand1, &operand2, &operator);

		int status;

		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("Nu am putut crea procesul");
		}

		if(child_pid == 0)
		{
			char storage_operand1[STORAGE_SIZE];

			char storage_operand2[STORAGE_SIZE];

			char storage_operator[2];



			storage_operator[0] = operator;
			storage_operator[1] = '\0';



			snprintf(storage_operand1, STORAGE_SIZE, "%d", operand1);

			snprintf(storage_operand2, STORAGE_SIZE, "%d", operand2);

			execl("slave", "slave", storage_operand1, storage_operand2, storage_operator, NULL);

			return 1;
		}

		wait(&status);

		char res = WEXITSTATUS(status);

		printf("Rezultat: %d \n", res);

		printf("Mai faceti si alte calcule ? (Tastati 1 daca da ) \n");

		scanf("%d", &read_status);
	}
	while(read_status == 1);

	return 0;
}