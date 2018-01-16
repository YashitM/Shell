#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

char *checkFlag(char **argv, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        if (strstr(argv[i], "-a") || strstr(argv[i], "-m"))
        {
            return argv[i];
        }
    }
    return "0";
}

int main(int argc, char **argv)
{
    char str[100000];
    DIR *dir;
    struct dirent *ent;
    int count = 0;
    if ((dir = opendir(".")) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            char *name = ent->d_name;
            if (name[0] == '.')
            {
                continue;
            }
            count += 1;
        }
    }
    if(strstr(checkFlag(argv,argc),"0")) {
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir(".")) != NULL)
        {
            while ((ent = readdir(dir)) != NULL)
            {
                char *name = ent->d_name;
                
                if ((name[0] == '.' && strlen(name) == 1) || (name[0] == '.' && name[1] == '.' && strlen(name) == 2)) {
                    printf("\033[0;34m");
                    printf("%s ", name);
                    printf("\033[0m");
                    continue;
                }
                else if(name[0] == '.') {
                    continue;
                }

                if (is_regular_file(name))
                {
                    printf("\033[0;32m");
                    printf("%s ", name);
                    printf("\033[0m");
                }
                else {
                    printf("\033[0;34m");
                    printf("%s ", name);
                    printf("\033[0m");
                }
            }
            printf("\n");
            closedir(dir);
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
        if(strstr(flag,"-a")) {
            DIR *dir;
            struct dirent *ent;
            if ((dir = opendir(".")) != NULL)
            {
                while ((ent = readdir(dir)) != NULL)
                {
                    char *name = ent->d_name;

                    if (is_regular_file(name))
                    {
                        printf("\033[0;32m");
                        printf("%s ", name);
                        printf("\033[0m");
                    }
                    else
                    {
                        printf("\033[0;34m");
                        printf("%s ", name);
                        printf("\033[0m");
                    }
                }
                printf("\n");
                closedir(dir);
            }
        }
        else if(strstr(flag,"-m")) {
            DIR *dir;
            struct dirent *ent;
            int counter = 0;
            if ((dir = opendir(".")) != NULL)
            {
                while ((ent = readdir(dir)) != NULL)
                {
                    char *name = ent->d_name;

                    if (name[0] == '.')
                    {
                        continue;
                    }

                    if (is_regular_file(name))
                    {
                        printf("\033[0;32m");
                        if(counter == count - 1) {
                            printf("%s", name);
                        }
                        else {
                            printf("%s, ", name);
                        }
                        printf("\033[0m");
                    }
                    else
                    {
                        printf("\033[0;34m");
                        if (counter == count - 1)
                        {
                            printf("%s", name);
                        }
                        else
                        {
                            printf("%s, ", name);
                        }
                        printf("\033[0m");
                    }
                    counter += 1;
                }
                printf("\n");
                closedir(dir);
            }
        }
        else {
            printf("Command Cannot Be Executed\n");
        }     
    }
    return 0;
}