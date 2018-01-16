#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int checkExists(char **argv, int argc)
{
	for (int i = 0; i < argc; i++)
	{
		if (strstr(argv[i], "-"))
		{
			return 1;
		}
	}
	return 0;
}

char *checkFlag(char **argv, int argc)
{
	for (int i = 0; i < argc; i++)
	{
		if (strstr(argv[i], "-n") || strstr(argv[i], "-E"))
		{
			return argv[i];
		}
	}
	return "0";
}

char *checkFlagHistory(char **argv, int argc)
{
	for (int i = 0; i < argc; i++)
	{
		if (strstr(argv[i], "-c"))
		{
			return argv[i];
		}
	}
	return "0";
}

void executeEcho(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("\n");
	}
	else if (argc > 1)
	{
		char str[100000];
		if (strstr(checkFlag(argv, argc), "0"))
		{
			int startQuote = 0;
			int endQuote = 0;
			int foundStartQuote = 0;
			int foundEndQuote = 0;
			for (int i = 0; i < argc; i++)
			{
				int lenArgument = strlen(argv[i]);
				if ((argv[i][0] == '"' || argv[i][0] == '\'') && foundStartQuote == 0)
				{
					startQuote = i;
					foundStartQuote = 1;
				}
				if ((argv[i][lenArgument - 1] == '"' || argv[i][lenArgument - 1] == '\'') && foundEndQuote == 0)
				{
					endQuote = i;
					foundEndQuote = 1;
					break;
				}
			}
			if (foundStartQuote == 1 && foundEndQuote == 1)
			{
				// printf("%s %s", argv[startQuote], argv[endQuote]);
				for (int i = startQuote; i <= endQuote; i++)
				{
					if (i == startQuote && i == endQuote)
					{
						for (int j = 1; j < strlen(argv[i]) - 1; j++)
						{
							printf("%c", argv[i][j]);
						}
						printf("\n");
						break;
					}
					else if (i == startQuote)
					{
						for (int j = 1; j < strlen(argv[i]); j++)
						{
							printf("%c", argv[i][j]);
						}
					}
					else if (i == endQuote)
					{
						for (int j = 0; j < strlen(argv[i]) - 1; j++)
						{
							printf("%c", argv[i][j]);
						}
						printf("\n");
						break;
					}
					else
					{
						printf("%s", argv[i]);
					}
					printf(" ");
				}
			}
			else
			{
				for (int i = 1; i < argc; i++)
				{
					printf("%s ", argv[i]);
				}
				printf("\n");
			}
		}
		else
		{
			char *flag;
			for (int i = 0; i < argc; i++)
			{
				if (strstr(argv[i], "-"))
				{
					flag = argv[i];
					break;
				}
			}
			if (strstr(flag, "-n"))
			{
				// without \n at the end
				// Finding position of the "/'
				int startQuote = 0;
				int endQuote = 0;
				int foundStartQuote = 0;
				int foundEndQuote = 0;
				for (int i = 0; i < argc; i++)
				{
					int lenArgument = strlen(argv[i]);
					if ((argv[i][0] == '"' || argv[i][0] == '\'') && foundStartQuote == 0)
					{
						startQuote = i;
						foundStartQuote = 1;
					}
					if ((argv[i][lenArgument - 1] == '"' || argv[i][lenArgument - 1] == '\'') && foundEndQuote == 0)
					{
						endQuote = i;
						foundEndQuote = 1;
						break;
					}
				}
				if (foundStartQuote == 1 && foundEndQuote == 1)
				{
					for (int i = startQuote; i <= endQuote; i++)
					{
						if (i == startQuote && i == endQuote)
						{
							for (int j = 1; j < strlen(argv[i]) - 1; j++)
							{
								printf("%c", argv[i][j]);
							}
							break;
						}
						else if (i == startQuote)
						{
							for (int j = 1; j < strlen(argv[i]); j++)
							{
								printf("%c", argv[i][j]);
							}
						}
						else if (i == endQuote)
						{
							for (int j = 0; j < strlen(argv[i]) - 1; j++)
							{
								printf("%c", argv[i][j]);
							}
							break;
						}
						else
						{
							printf("%s", argv[i]);
						}
						printf(" ");
					}
				}
				else
				{
					for (int i = 1; i < argc; i++)
					{
						if (!strstr(argv[i], "-n"))
						{
							if (i != argc - 1)
							{
								printf("%s ", argv[i]);
							}
							else
							{
								printf("%s", argv[i]);
							}
						}
					}
				}
			}
			else if (strstr(flag, "-E"))
			{
				int startQuote = 0;
				int endQuote = 0;
				int foundStartQuote = 0;
				int foundEndQuote = 0;
				for (int i = 0; i < argc; i++)
				{
					int lenArgument = strlen(argv[i]);
					if ((argv[i][0] == '"' || argv[i][0] == '\'') && foundStartQuote == 0)
					{
						startQuote = i;
						foundStartQuote = 1;
					}
					if ((argv[i][lenArgument - 1] == '"' || argv[i][lenArgument - 1] == '\'') && foundEndQuote == 0)
					{
						endQuote = i;
						foundEndQuote = 1;
						break;
					}
				}
				if (foundStartQuote == 1 && foundEndQuote == 1)
				{
					for (int i = startQuote; i <= endQuote; i++)
					{
						if (i == startQuote && i == endQuote)
						{
							for (int j = 1; j < strlen(argv[i]) - 1; j++)
							{
								printf("%c", argv[i][j]);
							}
							printf("\n");
							break;
						}
						else if (i == startQuote)
						{
							for (int j = 1; j < strlen(argv[i]); j++)
							{
								printf("%c", argv[i][j]);
							}
						}
						else if (i == endQuote)
						{
							for (int j = 0; j < strlen(argv[i]) - 1; j++)
							{
								printf("%c", argv[i][j]);
							}
							printf("\n");
							break;
						}
						else
						{
							printf("%s", argv[i]);
						}
						printf(" ");
					}
				}
				else
				{
					for (int i = 1; i < argc; i++)
					{
						if (!strstr(argv[i], "-E"))
						{
							if (i != argc - 1)
							{
								printf("%s ", argv[i]);
							}
							else
							{
								printf("%s", argv[i]);
							}
						}
					}
					printf("\n");
				}
			}
		}
	}
}

int checkNumber(char *numString)
{
	int num;
	char *ptr;
	num = strtol(numString, &ptr, 10);
	if (!(*ptr != '\0' || ptr == numString))
	{
		return 1;
	}
	return 0;
}

int getNumberOfLines(char *history_file_location)
{
	int numberOfLines = 0;
	int c;
	FILE *file;
	file = fopen(history_file_location, "r");
	if (file)
	{
		while ((c = getc(file)) != EOF)
		{
			if (c == '\n')
			{
				numberOfLines += 1;
			}
		}
		fclose(file);
	}
	return numberOfLines;
}

int	main() {
	int pid;
	char input_string[1000];
	char cwd[1000];
	char const_dir[1000];
	char *current_dir;
	int counter = 0;
	getcwd(const_dir, sizeof(const_dir));
	char history_file_location[1000];
	strcpy(history_file_location,const_dir);
	strcat(history_file_location,"/history_file.txt");
	while (1) {
		getcwd(cwd, sizeof(cwd));
		printf("\033[0;32m");
		printf("%s$ ",cwd);
		printf("\033[0m"); 
		fgets(input_string,100,stdin);
		FILE *file;
		file = fopen(history_file_location, "a");
		fprintf(file, "%s" ,input_string);
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
				if(len_array != 1) {
					if(strcmp(elements[1],"-")==0) {
						if(getenv("OLDPWD")) {
							char *previous_directory = getenv("OLDPWD");
							setenv("OLDPWD", current_dir, 1);
							chdir(previous_directory);
						}
						else {
							printf("bash: cd: OLDPWD not set\n");
						}
					}
					else if(strcmp(elements[1],"~")==0) {
						char *new_directory = getenv("HOME");
						setenv("OLDPWD", current_dir, 1);
						chdir(new_directory);
					}
					else {
						setenv("OLDPWD", current_dir, 1);
						chdir(elements[1]);
					}
				}
				else {
					char *new_directory = getenv("HOME");
					setenv("OLDPWD", current_dir, 1);
					chdir(new_directory);
				}
			}
			else if (strstr(first, "pwd")){
				printf("%s\n",cwd);
			}
			else if (strstr(first, "history")) {
				if(len_array == 1) {
					int c;
					FILE *file;
					file = fopen(history_file_location, "r");
					if (file)
					{
						while ((c = getc(file)) != EOF) {
							putchar(c);
						}
						fclose(file);
					}
				}
				else if(len_array == 2) {
					if (strstr(elements[1],"-")) {
						if (strcmp(elements[1],"-c") == 0) {
							fclose(fopen(history_file_location, "w"));
						}
						else
						{
							printf("bash: history: %s: invalid option\n", elements[1]);
						}
					}
					else if(checkNumber(elements[1])) {
						int num;
						char *ptr;
						num = strtol(elements[1], &ptr, 10);
						numberOfLines = getNumberOfLines(history_file_location);
						if(num < numberOfLines) {
							
						}
						else {
							int c;
							FILE *file;
							file = fopen(history_file_location, "r");
							if (file)
							{
								while ((c = getc(file)) != EOF)
								{
									putchar(c)
								}
								fclose(file);
							}
						}
					}
					else {
						printf("bash: history: numeric argument required\n");
					}
				}
				else {
					printf("bash: history: numeric argument required\n");
				}
			}
			else if (strstr(first, "cat")){
				pid = fork();
				char tempDirectory[1000];
				strcpy(tempDirectory, const_dir);
				strcat(tempDirectory, "/binaries/cat");
				if(pid == 0) {
					char *argv[] = {tempDirectory, (char *)elements};
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
			else if (strstr(first, "echo"))
			{
				executeEcho(len_array, elements);
			}
			else if (strstr(first, "ls")) {
				pid = fork();
				char tempDirectory[1000];
				strcpy(tempDirectory, const_dir);
				strcat(tempDirectory, "/binaries/ls");
				if (pid == 0)
				{
					char *argv[] = {tempDirectory, (char *)elements};
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
			else if (strstr(first,"date")) {
				pid = fork();
				char tempDirectory[1000];
				strcpy(tempDirectory, const_dir);
				strcat(tempDirectory, "/binaries/date");
				if (pid == 0)
				{
					char *argv[] = {tempDirectory, (char *)elements};
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
				char tempDirectory[1000];
				strcpy(tempDirectory, const_dir);
				strcat(tempDirectory, "/binaries/rm");
				if (pid == 0)
				{
					char *argv[] = {tempDirectory, (char *)elements};
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
				char tempDirectory[1000];
				strcpy(tempDirectory, const_dir);
				strcat(tempDirectory, "/binaries/mkdir");
				if (pid == 0)
				{
					char *argv[] = {tempDirectory, (char *)elements};
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