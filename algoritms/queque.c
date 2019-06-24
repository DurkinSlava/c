#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX 100
#define LEN 255

int spos = 0; //
int rpos = 0;

char *p[LEN];

void qstore(char *message);  // сохранить сообщение
void enter_message();        // ввод сообщения
void list_messages();        // просмотр сообщений
char *retrieve_message();    // извлечение сообщения
void delete_message();       // удаление сообщения

void queque()
{
    /* Пример работы со структурой данных очередь */
    int ch = 0;

    for (int i = 0; i < MAX; i++)
        p[i] = NULL;

    char s[80];

    for (;;)
    {
        printf("(S)tore    message\n");
        printf("(D)elete   message\n");
        printf("(L)ist     message\n");
        printf("(E)xit\n");
        printf("------------------\n");

        gets(s);
        *s = toupper(*s);

        switch(*s)
        {
            case 'S':
                enter_message();
                break;

            case 'D':
                delete_message();
                break;

            case 'L':
                list_messages();
                break;

            case 'E':
                exit(0);
                break;
            default:
                break;

        }



    }
}

void enter_message()
{
    /* Ввод сообщения от пользователя */

    char s[LEN], *p = NULL;
    do
    {
        printf("Input a message № %d:", spos + 1);
        gets(s);
        if (*s == 0)
            break;

        p = (char *)malloc(strlen(s) + 1);
        if (!p)
        {
            printf("Not enough memory.\n");
            return;
        }
        strcpy(p, s);

        qstore(p);

    }
    while(*s);

}

void qstore(char *pmessage)
{
    /* сохранить сообщение в очередь */

    if (spos == MAX)
    {
        printf("Queque is full.");
        return;
    }

    p[spos++] = pmessage;

}

void list_messages()
{
    /* Вывод сообщений на экран. */

    for (int i = rpos; i < spos; i++)
        printf("%d. %s\n" , i+1, p[i]);

}

void delete_message()
{
    char *p;
    if ((p = retrieve_message()) == NULL)
    {
        printf("Queque is empty.\n");
        return;

    }

    printf("%s\n", p);
}

char *retrieve_message()
{
    /* извлечение сообщения */
    if (rpos == spos)
        return NULL;

    return p[rpos++];
}

