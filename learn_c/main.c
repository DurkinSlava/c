#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int global_var;
int x, y;

void func1();
void func2();
/* Последовательность чисел */
int series();

/* проверка вхождения символа */
int is_in(char *s, char c);
/* меняет пробел на тире */
void sp_to_dash(const char *str);

/* возведение в степень */
int int_pwr(register int num, register int e);

/* угадай число */
void guess_the_number();
/* удаляет ведущие пробелы и строки*/
void delete_begin_space();
/* двухмерный массив*/
void two_dimesional_array();

/* локальные массивы переменной длины */
void variable_length_array(int dim);

int main()
{
    char s[80];
    char ch;
    extern int first, last;
    register int i, j;
    wchar_t wc;

    variable_length_array(3);
    variable_length_array(6);
    variable_length_array(10);

    //grade_students();


    //two_dimesional_array();
//
//    delete_begin_space();
//
//    guess_the_number();


    wc = L'x';
    printf("sizeof wc = %d\n", sizeof(wc));

    x = 1;
    y = 2;

    printf("%.1f\n", (float)1/2);

    printf("global_var init value = %d\n", global_var);

    printf("first = %d, last = %d\n", first, last);
    print_x_y();

    printf("%d\n", series());
    printf("%d\n", series());
    printf("%d\n", series());

    printf("2 ^ %d = %d bytes\n", 10 , int_pwr(2, 20));


    {
        char str[80];
        strcpy(str, "C is wonderfull!");
        printf("%s\n", str);

    }

    sp_to_dash("We eat our dinner.");

    func1();
    func2();

    printf("Input a string:");
    gets(s);
    printf("Input a character:");
    scanf("%c", &ch);

    if (is_in(s, ch))
        printf("character %c is in string \"%s\"", ch, s);
    else
        printf("character %c is not in string \"%s\"", ch, s);

    return 0;
}

int is_in(char *s, char c)
{
    /* проверяет вхождение символа в строку */

    while(*s)
    {
        if (*s == c)
            return 1;
        s++;
    }

    return 0;
}

void func1()
{
    global_var = 100;
}

void func2()
{
    printf("global_var = %d\n", global_var);

}

void sp_to_dash(const char *str)
{
    /* меняет пробел на тире */

    while (*str)
    {
        if (*str==' ')
            putchar('-');
        else
            putchar(*str);
        str++;
    }
    printf("\n");

}
int first = 10, last = 20;

int series()
{
    /* последовательность целых чисел */
    static int series_num;
    static char a[SIZE];
    for (int i = 0; i < SIZE; i++)
        printf("%d ", *(a + i));
    printf("\n");


    return ++series_num;

}

int int_pwr(register int num, register int e)
{
   /* возведение в степень */
    register int temp = 1;

    for (;e; e--)
        temp *= num;

    return temp;
}

void guess_the_number()
{
    /* угадай число */

    int magic; /* magic number   */
    int guess; /* attempt player */

    const int numbers = 3;
    const int count_of_attempts = 5;

    int attempt = count_of_attempts;

    while (attempt)
    {
        magic = rand() % 5 + 1;

        printf("Attempt №%d Guess the magic number from 1 to %d:",
            count_of_attempts + 1 - attempt, numbers);

        scanf("%d", &guess);
        if (guess == magic)
            printf("Congratilations! You guessed it!\n");
        else
            printf("Sorry. You where wrong. Correct answer is %d\n", magic);

        --attempt;

    }

}

/* удаляет ведущие пробелы и строки*/
void delete_begin_space()
{
    char s[80], *pstr;
    pstr = s;

    printf("Input a string:");
    gets(s);

    for (; *pstr == ' '; pstr++);
    printf("You entered:%s\n", pstr);

}

void two_dimesional_array()
{
    /* двухмерный массив */

    int a[3][4];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            a[i][j] = i * 4 + j + 1;

    printf("Two-dimensional array:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%2d ", *((int *)a+(i*4) + j));
        printf("\n");
    }
}

void variable_length_array(int dim)
{
    /* массивы переменной длины */
    int a[dim];
    for (int i = 0; i < dim; i++)
        a[i] = i + 1;

    for (int i = 0; i < dim; i++)
        printf("%d ", *(a+i));
    printf("\n");
}
