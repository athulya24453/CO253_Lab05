#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char s[])
{
    int n = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        switch (s[i])
        {
        case 'I':
            if (s[i + 1] == 'V' || s[i + 1] == 'X')
            {
                n--;
            }
            else
            {
                n++;
            }
            break;

        case 'V':
            n += 5;
            break;

        case 'X':
            if (s[i + 1] == 'L')
            {
                n -= 10;
            }
            else
            {
                n += 10;
            }
            break;

        case 'L':
            n += 50;
            break;
        }
    }
    return n;
}

char *name(char *s)
{
    int i;
    int len;
    for (i = 0; i < strlen(s); i++)
    {
        if (isspace(s[i]) != 0)
        {
            len = i;
            break;
        }
    }

    char *nameArr = malloc((len + 1) * sizeof(char));

    for (int j = 0; j < len; j++)
    {
        nameArr[j] = s[j];
    }
    nameArr[len] = 0;
    return nameArr;
}

int number(char *s)
{
    int i;
    int len;
    for (i = 0; i < strlen(s); i++)
    {
        if (isspace(s[i]) != 0)
        {
            len = i;
            break;
        }
    }

    char *nArr = malloc((strlen(s) - len - 1) * sizeof(char));

    for (int j = len + 1; j < strlen(s) + 1; j++)
    {
        nArr[j - len - 1] = s[j];
    }

    char numStr[10];

    strcpy(numStr, nArr);

    int numberAns = romanToInt(numStr);
    return numberAns;
}

char **sortRoman(int names_count, char **names, int *result_count)
{
    *result_count = names_count;
    for (int i = 0; i < names_count; i++)
    {
        int fixnum = number(names[i]);
        char *fixname = name(names[i]);

        for (int j = 0; j < names_count; j++)
        {
            int comnum = number(names[j]);
            char *comname = name(names[j]);

            if (strcmp(fixname, comname) > 0)
            {
                char *tmp = names[i];
                names[i] = names[j];
                names[j] = tmp;
            }

            else if (strcmp(fixname, comname) == 0)
            {
                if (fixnum > comnum)
                {
                    char *tmp = names[i];
                    names[i] = names[j];
                    names[j] = tmp;
                }
            }
        }
    }

    for (int j = 0; j < names_count / 2; j++)
    {
        char *tmp = names[j];
        names[j] = names[names_count - j - 1];
        names[names_count - j - 1] = tmp;
    }
    return names;
}

int main()
{

    char **names;
    int lenth, k;

    lenth = 6;
    names = (char **)malloc(lenth * sizeof(char *));

    *(names) = "Steven XL";
    *(names + 1) = "Steven XVI";
    *(names + 2) = "David IX";
    *(names + 3) = "Mary XV";
    *(names + 4) = "Mary XIII";
    *(names + 5) = "Mary XX";

    for (k = 0; k < lenth; k++)
    {
        printf("%s\n", *(names + k));
    }

    int result_count;
    char **sorted = sortRoman(lenth, names, &result_count);

    // sortRoman(lenth,names,result_count);

    // sorted = sortRoman(lenth,names,result_count);

    printf("\n");

    for (k = 0; k < result_count; k++)
    {
        printf("%s\n", *(sorted + k));
    }

    return 0;
}