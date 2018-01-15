#include<stdio.h>
#include<string.h>

char *checkFlag(char **argv, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        if (strstr(argv[i], "-a") || strstr(argv[i], "-i"))
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
            if(strstr(flag,"-a")) {
                  
            }
            else if(strstr(flag,"-i")) {

            }
        }
    }
    return 0;
}