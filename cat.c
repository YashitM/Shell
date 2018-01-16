#include<stdio.h>
#include<string.h>

char *checkFlag(char **argv, int argc) {
    for(int i=0; i<argc; i++) {
        if (strstr(argv[i], "-")){
            return argv[i];
        }
    }
    return "0";
}

int main(int argc, char **argv) {
    if (argc < 4)
    {
        printf("cat: No such file or directory\n");
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
            int foundFileName = 0;
            for (int i = 3; i < argc; i++)
            {
                if (strstr(argv[i], "-"))
                {
                    flag = argv[i];
                }
                else if (foundFileName == 0) {
                    foundFileName = 1;
                }
            }
            if (foundFileName == 0) {
                printf("cat: No such file or directory\n");
                return 0;
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
                            printf("%d ", counter);
                            while (1)
                            {
                                ch = fgetc(file);
                                if (ch == EOF)
                                {
                                    break;
                                }
                                if (ch == '\n')
                                {
                                    counter += 1;
                                    printf("$");
                                    printf("%c",ch);
                                    printf("%d ",counter);
                                }
                                else {
                                    printf("%c", ch);
                                }
                            }
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
                            char ch;
                            while (1)
                            {
                                ch = fgetc(file);
                                if (ch == EOF)
                                {
                                    break;
                                }
                                if (ch == '\n')
                                {
                                    printf("$");
                                }
                                printf("%c", ch);
                            }
                            fclose(file);
                        }
                        else
                        {
                            printf("cat: No such file or directory\n");
                        }
                    }
                }
            }
            else {
                printf("cat: invalid option %s\n", flag);
            }
        }
    }
}