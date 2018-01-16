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
    if (strstr(checkFlag(argv, argc), "0") && argc == 3)
    {
        printf("%s", asctime(localtime(&t)));
    }
    else if (argc == 4 && !strstr(checkFlag(argv, argc), "0"))
    {
        char *flag;
        for (int i = 3; i < argc; i++)
        {
            if (strstr(argv[i], "-"))
            {
                flag = argv[i];
                break;
            }
        }
        if (strstr(flag, "-u"))
        {
            printf("%s", asctime(gmtime(&t)));
        }
        else if (strstr(flag, "-R"))
        {
            char date[1000];
            strftime(date, sizeof(date), "%a %d %b %Y %T %z", localtime(&t));
            printf("%s\n", date);
        }
        else {
            printf("date: invalid option %s\n", flag);
        }
    }
    else {
        printf("date: invalid date\n");
    }
}