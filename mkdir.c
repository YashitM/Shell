#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

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
    char str[100000];
    time_t t = time(NULL);
    if(argc == 3) {
        printf("mkdir: missing operand\n");
        return 0;
    }
    if (strstr(checkFlag(argv, argc), "0"))
    {
        for(int i=3; i<argc; i++) {
            if(mkdir(argv[i], 0777)!=0) {
                printf("mkdir: cannot create directory '%s'", argv[i]);
            }
        }
    }
    else
    {
        char *flag;
        int foundFileName = 0;
        for (int i = 3; i < argc; i++)
        {
            if (strstr(argv[i], "-"))
            {
                flag = argv[i];
            }
            else if (foundFileName == 0)
            {
                foundFileName = 1;
            }
        }
        if (foundFileName == 0)
        {
            printf("mkdir: missing operand\n");
            return 0;
        }
        for (int i = 0; i < argc; i++)
        {
            if (strstr(argv[i], "-"))
            {
                flag = argv[i];
                break;
            }
        }
        if (strstr(flag, "-v"))
        {
            for (int i = 3; i < argc; i++)
            {
                if(!strstr(argv[i],"-")) {
                    if (mkdir(argv[i], 0777) != 0)
                    {
                        printf("mkdir: cannot create directory '%s'\n", argv[i]);
                    }
                    else {
                        printf("mkdir: created directory '%s'\n",argv[i]);
                    }
                }
            }
        }
        else if (strstr(flag, "-m"))
        {   
            int num;
            char *ptr;
            char *numString;
            char permission[100];
            for (int i = 3; i < argc; i++)
            {
                num = strtol(argv[i],&ptr,10);
                numString = argv[i];
                if (!strstr(argv[i], "-") && !(*ptr!='\0' || ptr==argv[i]))
                {
                    break;
                }
            }
            for (int i = 3; i < argc; i++)
            {
                if (!strstr(argv[i], "-") && !strstr(argv[i],numString))
                {
                    if (mkdir(argv[i],num) != 0)
                    {
                        printf("mkdir: cannot create directory '%s'\n", argv[i]);
                    }
                    else
                    {
                        printf("mkdir: created directory '%s'\n", argv[i]);
                    }
                    break;
                }
            }
        }
        else {
            printf("mkdir: invalid option %s\n", flag);
        }
    }
}