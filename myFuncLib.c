#include <stdio.h>
#include <math.h>
#include <string.h>

int isPrime(int num);
int antiNumber(int num);
void bublleSort(int num[], int size);
int isLeapYear(int year);
double average(int a[], int n);
char *delSonStr(char str1[], char str2[]);

int isPrime(int num)
{
    int i;
    for (i = 2; i < num; i++)
        if (num % i == 0)
            return 0;
    if (num == 2)
        return 1;
    else if (num == 1 || num == 0)
        return 0;
    else
        return 1;
}

int antiNumber(int num) // #include <math.h>
{
    int out = 0, t, time = 0, len = 0, n = num;
    do
    {
        n /= 10;
        len++;
    } while (n > 0);
    n = num;
    for (int i = 1; i <= len; i++)
    {
        t = n % 10;
        out += t * pow(10, len - i);
        n /= 10;
    }
    return out;
}

void bublleSort(int num[], int size) // 根据实际需要更改数据类型和排序方式
{
    int temp;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (num[j] > num[j + 1])
            {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
}

int isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return 1;
    else if (year % 400 == 0)
        return 1;
    else
        return 0;
}

double average(int a[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum / n;
}

char *delSonStr(char str1[], char str2[]) // include <stting.h>
{
    int n = strlen(str2), i = 0;
    char *position = strstr(str1, str2), *pt;
    if (position == NULL)
        return NULL;
    while (position != NULL)
    {
        for (pt = str1; *pt != '\0'; pt++)
        {
            if (pt == position)
            {
                pt = pt + n - 1;
                continue;
            }
            else
            {
                str1[i] = *pt;
                i++;
            }
        }
        str1[i] = '\0';
        position = strstr(str1, str2);
        i = 0;
    }
    return str1;
}