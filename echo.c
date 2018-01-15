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
            else {
                for (int i = 3; i < argc; i++)
                {
                    printf("%s ", argv[i]);
                }
                printf("\n");
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
            if(strstr(flag,"-n")) {
                // without \n at the end
                // Finding position of the "/'
                int startQuote = 0;
                int endQuote = 0;
                int foundStartQuote = 0;
                int foundEndQuote = 0;
                for(int i = 0; i < argc; i++) {
                    int lenArgument = strlen(argv[i]);
                    if((argv[i][0] == '"' || argv[i][0] == '\'') && foundStartQuote == 0) {
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
                if(foundStartQuote == 1 && foundEndQuote == 1) {
                    for(int i = startQuote; i <= endQuote; i++) {
                        if(i == startQuote && i == endQuote) {
                            for (int j = 1; j < strlen(argv[i])-1; j++)
                            {
                                printf("%c", argv[i][j]);
                            }
                            break;
                        }
                        else if(i == startQuote) {
                            for(int j = 1; j < strlen(argv[i]); j++) {
                                printf("%c", argv[i][j]);
                            }
                        }
                        else if(i == endQuote) {
                            for (int j = 0; j < strlen(argv[i])-1; j++)
                            {
                                printf("%c", argv[i][j]);
                            }
                            break;
                        }
                        else {
                            printf("%s", argv[i]);
                        }
                        printf(" ");
                    }
                }
                else {
                    for (int i = 3; i < argc; i++)
                    {
                        if (strstr(argv[i], "\""))
                        {
                        }
                        else if (!strstr(argv[i], "-n"))
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