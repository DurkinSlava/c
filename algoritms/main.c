#include <stdio.h>
#include <stdlib.h>

int count = 1;

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void permutatons(int *a, int i, int N)
{
    /* Рекурсивный алгоритм перестановок */

    if (i == N )
    {
        printf("%d - ", count++);
        for (int j = 0; j < N; j++)
            printf("%d ", *(a + j));
        printf("\n");
    }
    else
    {
        for (int j = i; j < N; j++)
        {
            swap(&a[i], &a[j]);

            permutatons(a, i + 1, N);

            swap(&a[i], &a[j]);
        }
    }
}

void narayana(int *a, int N)
{
    /* Перестановки алгоритм Нарайны
      в лексикографическом порядке
    */

    //1. Смотрим, надо ли чего менять

    int perm  = 1;
    int count = 1;

    printf("%d - ", count++);
            for (int i = 0 ; i < N; i++)
                printf("%d ", a[i]);
            printf("\n");

    while (perm)
    {
        perm = 0;
        int i = N;

        while (i > 0)
        {
            i--;
            if (a[i - 1] < a[i])
            {
                i -= 1;
                perm = 1;
                break;
            }

        }
        // Шаг №2
        if (perm)
        {
            int j = N;

            while (j > 0)
            {
                j--;
                if (a[i] < a[j])
                    break;

            }
            swap(&a[i], &a[j]);

            // Шаг №3 меняем местами с j + 1


            int k = N - 1;
            for (int t = i + 1; t < k; t++, k--)
                swap(&a[t], &a[k]);

            // Шаг №4 Вывод на печать.
            printf("%d - ", count++);
            for (int i = 0 ; i < N; i++)
                printf("%d ", a[i]);
            printf("\n");

        }


    }
}

void bin_search()
{
    /* Алгортим бинарного поиска */

    const int SIZE = 1000;
    int a[SIZE];

    for (int i = 0; i < SIZE; i++)
        a[i] = i + 1;

    printf("Введите целое число:");
    int num, step = 0;

    scanf("%d", &num);

    int i = 0;
    int j = SIZE - 1;
    int t;

    while (i <= j)
    {
        step++;
        t = (i + j) / 2;
        printf("step %4d a[%4d] = %4d, a[%4d] = %4d, mid = a[%4d] = %4d\n", step, i, a[i], j, a[j], t, a[t]);
        if (a[t] == num)
            break;
        else
        {
            if (a[t] < num)
            {
                i = t;
                i++;
            }

            else
            {
                j = t;
                j--;
            }

        }
    } //while (i < j)

    if (a[t] == num)
        printf("%d finded!", num);
    else
        printf("%d do not finded.", num);

}


int main()
{

    const int N = 4;

    int a[N];

    for (int i = 0; i < N; i++)
        a[i] = i + 1;

   // bin_search();

    //permutatons(a, 0, N);
    // narayana(a, N);

    //free(a);

    cyclic_queque();




    return 0;
}
