/* Пример односвязного списка */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int field; //поле данных
    struct list * ptr; // указатель на следующий элемент
} list;

list *init(int a) // значение первого узла
{
    /* инициализация */
    list *lst;
    lst = (list *)malloc(sizeof(list));
    lst->field = a;
    lst->ptr = NULL;

    return lst;
}

list *add_item(list *lst, int number)
{
    /* Добавление элемента в список */
    list *temp, *p;

    temp = (list*)malloc(sizeof(list));
    p = lst->ptr; //сохранение указателя предыдущего узла
    lst->ptr = temp; //предыдщий теперь указывает на текущий
    temp->field = number;
    temp->ptr = p; // Текущий указывает на следующий

    return temp;
}
