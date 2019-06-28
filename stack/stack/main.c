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
        printf("Your choice:");

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
                list_stack();
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
    int value = 0;
    printf("-1 stop enter\n");
    printf("Input integer number № %d:", tos + 1);
    scanf("%d", &value);

    while (!(value==-1))
    {
        if (tos == MAX)
        {
            printf("stack is full\n");
            break;
        }
        else
            stack[tos++] = value;

        printf("Input integer number № %d:", tos + 1);
        scanf("%d", &value);
    }

}

void pop()
{
    /* извлечь из стэка */

    if (!tos)
        printf("stack is empty.\n");
    else
        printf("%d\n", stack[--tos]);

}

void list_stack()
{
    /* Печать стэка */
    for (int i = 0; i < MAX; i++)
        printf("%d ", stack[i]);
    printf("\n");
}
