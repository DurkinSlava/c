/* пример работы с массивом указателей*/
#include <stdio.h>
#include <string.h>
char *names[] =
{
    "Barbara",
    "Celarent",
    "Darii",
    "Ferioque",
    NULL
};
/* поиск в массиве */
int search(char *p[], char *name);

void array_of_pointers()
{
    char s[80];
    printf("Input a modus:");
    gets(s);

    if (search(names, s) !=- 1)
        printf("%s in list\n", s);
    else
        printf("%s not in list\n", s);


}

int search(char *p[], char *name)
{
    /* поиск в массиве */
    for (int i = 0; p[i]; i++)
        if (!strcmp(p[i], name))
            return i;

    return -1;
}


