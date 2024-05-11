#include <stdio.h>
#include <math.h>

int isPrime(int num);
int antiNumber(int num);
void bublleSort(int num[], int size);
int isLeapYear(int year);
double average(int a[], int n);

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