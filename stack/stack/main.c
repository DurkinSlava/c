#include <stdio.h>
#include <stdlib.h>


#define MAX 3

int stack[MAX];
int tos = 0;

void push();        // добавить в стэк
void pop();         // извлечь из стэка
void list_stack();  // печать стэка

int main()
{
    char s[80];

    for (;;)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. List\n");
        printf("4. Exit\n");

        gets(s);

        switch(*s)
        {
            case '1':
                push();
                break;

            case '2':
                pop();
                break;

            case '3':
                pop();
                break;

            case '4':
                exit(0);
                break;

            default:
                break;

        }


    }

    return 0;
}

void push()
{
    /* Добавить в стэк */
    char s[80];

    gets(s);

    while (*s)
    {
        if (tos == MAX)
        {
            printf("stack is full\n");
            break;
        }
        else
            stack[tos++] = *s;

        gets[s];
    }

}

void pop()
{
    /* извлесь из стэка */

    if (!tos)
        printf("stack is empty.\n");
    else
        printf(stack[--tos]);

}

void list_stack()
{
    /* Печать стэка */
    for (int i = 0; i < MAX; i++)
        printf("%d ", stack[i]);
}
