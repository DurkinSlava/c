#include <stdio.h>
#include <stdlib.h>

struct address
{
    char name[40];
    char street[40];
    char city[20];
    char state[3];
    char zip[11];
    struct address *next;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
