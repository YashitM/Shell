#include <stdio.h>
#include <string.h>
#include <time.h>

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
    if (strstr(checkFlag(argv, argc), "0"))
    {
        if(remove(argv[2])) {
            printf("remove: No such file/directory found\n");
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
        if (strstr(flag, "-v"))
        {
            for (int i = 3; i < argc; i++)
            {
                if (!strstr(argv[i], "-"))
                {
                    if (!remove(argv[i]))
                    {
                        printf("removed '%s'\n", argv[i]);
                        break;
                    }
                    else
                    {
                        printf("remove: No such file/directory found\n");
                        break;
                    }
                }
            }
        }
        else if (strstr(flag, "-d"))
        {
            for (int i = 3; i < argc; i++)
            {
                if (!strstr(argv[i], "-"))
                {
                    if (!remove(argv[i]))
                    {
                        break;
                    }
                    else
                    {
                        printf("rm: cannot remove '%s': No such file or directory\n", argv[i]);
                        break;
                    }
                }
            }
        }
    }
}