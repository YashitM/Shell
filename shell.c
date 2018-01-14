#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

// Internal External Command separation

char *checkExists(char **argv, int argc)
{
	for (int i = 0; i < argc; i++)
	{
		if (strstr(argv[i], "-c"))
		{
			return 1;
		}
	}
	return "0";
}

int	main() {
	int pid;
	char input_string[1000];
	char cwd[1000];
	char *current_dir;
	int counter = 0;
	while (1) {
		getcwd(cwd, sizeof(cwd));
		printf("\033[0;32m");
		printf("%s$ ",cwd);
		printf("\033[0m"); 
		fgets(input_string,100,stdin);
		FILE *file;
		file = fopen("history_file.txt", "a");
		fprintf(file, input_string);
		fclose(file);
		if(input_string[0]!='\n') {
			input_string[strcspn(input_string,"\r\n")]=0;
			char *p = strtok (input_string," ");
			char *first = p;
			char *elements[100];
			int len_array = 0;
			while( p != NULL ) {
				elements[len_array] = p;
				p = strtok(NULL," ");
				len_array += 1;
			}
			elements[len_array] = NULL;
			if(strstr(first,"exit")) {
				return 0;
			}
			else if(strstr(first,"cd")){
				current_dir = strcat(cwd, "/");
				chdir(strcat(current_dir, elements[1]));
			}
			else if (strstr(first, "pwd")){
				printf("%s\n",cwd);
			}
			else if (strstr(first, "history")) {
				printf("%d LOL", checkExists(elements, len_array);
				if(!checkExists(elements, len_array)) {
					int c;
					FILE *file;
					file = fopen("history_file.txt", "r");
					if (file)
					{
						while ((c = getc(file)) != EOF)
							putchar(c);
						fclose(file);
					}
				}
				else {
					fclose(fopen("history_file.txt", "w"));
				}
			}
			else if (strstr(first, "cat")){
				pid = fork();
				if(pid == 0) {
					char *argv[] = {"./cat", elements};
					if(execvp(argv[0],argv)<0) {
						printf("\033[0;33m");
						printf("Command Can't Be Executed\n");
						printf("\033[0m");
						exit(1);
					}
				}
				else {
					wait(NULL);
				}
			}
			else if (strstr(first,"date")) {
				pid = fork();
				if (pid == 0)
				{
					char *argv[] = {"./date", elements};
					if (execvp(argv[0], argv) < 0)
					{
						printf("\033[0;33m");
						printf("Command Can't Be Executed\n");
						printf("\033[0m");
						exit(1);
					}
				}
				else
				{
					wait(NULL);
				}
			}
			else if(strstr(first,"rm")) {
				pid = fork();
				if (pid == 0)
				{
					char *argv[] = {"./rm", elements};
					if (execvp(argv[0], argv) < 0)
					{
						printf("\033[0;33m");
						printf("Command Can't Be Executed\n");
						printf("\033[0m");
						exit(1);
					}
				}
				else
				{
					wait(NULL);
				}
			}
			else if(strstr(first,"mkdir")) {
				pid = fork();
				if (pid == 0)
				{
					char *argv[] = {"./mkdir", elements};
					if (execvp(argv[0], argv) < 0)
					{
						printf("\033[0;33m");
						printf("Command Can't Be Executed\n");
						printf("\033[0m");
						exit(1);
					}
				}
				else
				{
					wait(NULL);
				}
			}
			else {
				pid = fork();
				if(pid == 0){
					if(execvp(elements[0], elements)<0) {
						printf("\033[0;33m");
						printf("Command Can't Be Executed\n");
						printf("\033[0m"); 
						exit(1);
					}
				}
				else{
					wait(NULL);
				}
			}
		}
	}
	return 0;
}