#include<stdio.h>
#include<string.h>

char *checkFlag(char **argv, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        if (strstr(argv[i], "-"))
        {
            return argv[i];
        }
    }
    return "0";
}

int main(int argc, char **argv)
{ 
    printf("%d\n",argc);
    for(int i=0; i<argc; i++) {
        printf("%s\n",argv[i]);
    }
    if (argc == 3)
    {
        printf("\n");
    }
    else
    {
        char str[100000];
        if(strstr(checkFlag(argv,argc),"0")) {
            for (int i = 3; i < argc; i++)
            {
                FILE *file;
                file = fopen(argv[i], "rb");
                if (file)
                {
                    while (fscanf(file, "%s", str) != EOF)
                    {
                        printf("%s", str);
                    }
                    printf("\n");
                    fclose(file);
                }
                else
                {
                    printf("cat: No such file or directory\n");
                }
            }
        }
        else {
            char *flag;
            for (int i = 0; i < argc; i++)
            {
                if (strstr(argv[i], "-"))
                {
                    flag = argv[i];
                    break;
                }
            }
            if(strstr(flag,"-nE") || strstr(flag,"-En")) {
                for (int i = 3; i < argc; i++)
                {
                    if (!strstr(argv[i], "-"))
                    {
                        FILE *file;
                        file = fopen(argv[i], "rb");
                        if (file)
                        {
                            int counter = 1;
                            char ch;
                            printf("$ %d ", counter);
                            while (1)
                            {
                                ch = fgetc(file);
                                if (ch == EOF)
                                {
                                    break;
                                }
                                printf("%c", ch);
                                if (ch == '\n')
                                {
                                    counter += 1;
                                    printf("$ %d ", counter);
                                }
                            }
                            printf("\n\n");
                            fclose(file);
                        }
                        else
                        {
                            printf("cat: No such file or directory\n");
                        }
                    }
                }
            }
            else if(strstr(flag,"-n")) {
                // Show Number at output lines
                for (int i = 3; i < argc; i++)
                {
                    if(!strstr(argv[i],"-")) {
                        FILE *file;
                        file = fopen(argv[i], "rb");
                        if (file)
                        {
                            int counter = 1;
                            char ch;
                            printf("%d ", counter);
                            while(1) {
                                ch = fgetc(file);
                                if (ch == EOF) {
                                    break;
                                }
                                printf("%c", ch);
                                if (ch == '\n') {
                                    counter+=1;
                                    printf("%d ", counter);
                                }
                            }
                            printf("\n\n");
                            fclose(file);
                        }
                        else
                        {
                            printf("cat: No such file or directory\n");
                        }
                    }
                }
            }
            else if(strstr(flag,"-E")) {
                for (int i = 3; i < argc; i++)
                {
                    if (!strstr(argv[i], "-"))
                    {
                        FILE *file;
                        file = fopen(argv[i], "rb");
                        if (file)
                        {
                            int counter = 1;
                            char ch;
                            printf("$ ");
                            while (1)
                            {
                                ch = fgetc(file);
                                if (ch == EOF)
                                {
                                    break;
                                }
                                printf("%c", ch);
                                if (ch == '\n')
                                {                                    counter += 1;
                                    printf("$ ");
                                }
                            }
                            printf("\n\n");
                            fclose(file);
                        }
                        else
                        {
                            printf("cat: No such file or directory\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}