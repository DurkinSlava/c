/* Простая база данных оценок студентов. */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define CLASSES 3
#define GRADES 9

int a[CLASSES][GRADES];

void enter_grades();
int get_grade(int num);
void disp_grades(int g[][GRADES]);

void grade_students()
{
    char ch, str[80];

    for (;;)
    {

        do
        {
            printf("(E)nter grades\n");
            printf("(P)rint grades\n");
            printf("E(x)it\n");
            gets(str);
            ch = toupper(*str);

        }
        while (ch != 'E' &&  ch != 'P' && ch != 'X');

        switch (ch)
        {
        case 'E':
            enter_grades();
            break;

        case 'P':
            disp_grades(a);
            break;

        case 'X':
            exit(0);

        }
    }
}

int get_grade(int num)
{
    char s[80];

    /* input student's grade */
    printf("Enter grade of student №%d:", num);
    gets(s);

    return atoi(s);

}

void enter_grades()
{
    for (int i = 0; i < CLASSES; i++)
    {
        printf("Class number %d:\n", i + 1);

        for (int j = 0; j < GRADES; j++)
        {
            a[i][j] = get_grade(j + 1);
        }
    }
}

void disp_grades(int g[][GRADES])
{
    for (int i = 0; i < CLASSES; i++)
    {
        printf("Class number %d:\n", i + 1);

        for (int j = 0; j < GRADES; j++)
        {
            printf("%d ", g[i][j]);

            if ((j + 1) % 3 == 0)
                printf("\n");
        }
    }
}
