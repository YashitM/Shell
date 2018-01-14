#include<stdio.h>
#include<string.h>

char *checkFlag(char **argv, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        if (strstr(argv[i], "-n") || strstr(argv[i], "-e"))
        {
            return argv[i];
        }
    }
    return "0";
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        printf("\n");
    }
    else if(argc > 3)
    {
        char str[100000];
        if(strstr(checkFlag(argv,argc),"0")) {
            for (int i = 3; i < argc; i++)
            {
                printf("%s ", argv[i]);
            }
            printf("\n");
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
            if(strstr(flag,"-n")) {
                // without \n at the end
                for (int i = 3; i < argc; i++)
                {
                    if(!strstr(argv[i],"-n")) {
                        if(i != argc - 1) {
                            printf("%s ", argv[i]);
                        }
                        else {
                            printf("%s", argv[i]);
                        }
                    }
                }
            }
            else if(strstr(flag,"-e")) {
                for (int i = 3; i < argc; i++)
                {
                    if (!strstr(argv[i], "-e"))
                    {
                        
                    }
                }
            }
        }
    }
    return 0;
}