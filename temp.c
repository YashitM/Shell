#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *options[3] = {"-n", "-e", "-E"};
bool op[3];

int atoi(char *s, int base = 8)
{
    int ans = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        ans *= base;
        ans += (int)(s[i] - '0');
    }
    return ans;
}

int processOptions(int argc, char **argv)
{
    for (int k = 1; k < argc; k++)
    {
        bool f = false;
        for (int i = 0; i < 3; i++)
            if (strcmp(options[i], argv[k]) == 0)
                f = op[i] = true;
        if (!f)
            return k;
    }
    return argc;
}

void processStr(char *src, char *dst)
{
    if (!op[1])
    {
        strcpy(dst, src);
        return;
    }
    int i = 0, j = 0, cur = 0, clen;
    char code[5];
    for (; i < strlen(src); i++)
    {
        if (cur == 0)
        {
            if (src[i] != '\\')
                dst[j++] = src[i];
            else
                cur = 1;
        }
        else if (cur == 1)
        {
            switch (src[i])
            {
            case 'b':
                dst[j++] = '\b';
                break;
            case 't':
                dst[j++] = '\t';
                break;
            case 'v':
                dst[j++] = '\v';
                break;
            case 'a':
                dst[j++] = '\a';
                break;
            case '\\':
                dst[j++] = '\\';
                break;
            case '0':
                cur = 2;
                clen = 0;
                code[clen++] = '0';
                break;
            default:
                dst[j++] = '\\';
                dst[j++] = src[i];
            }
            if (cur == 1)
                cur = 0;
        }
        else if (cur == 2)
        {
            if (src[i] >= '0' && src[i] <= '9')
                code[clen++] = src[i];
            else
            {
                code[clen] = 0;
                dst[j++] = (char)atoi(code);
                if (src[i] == '\\')
                    cur = 1;
                else
                {
                    dst[j++] = src[i];
                    cur = 0;
                }
            }
        }
    }
    if (cur == 2)
    {
        code[clen] = 0;
        dst[j++] = (char)atoi(code);
    }
    dst[j] = 0;
}

int main(int argc, char **argv)
{
    op[2] = true;
    int p = processOptions(argc, argv);
    char res[256];
    for (int i = p; i < argc; i++)
    {
        processStr(argv[i], res);
        if (i + 1 < argc)
            printf(" ");
        printf("%s", res);
    }
    if (!op[0])
        puts("");
    return 0;
}