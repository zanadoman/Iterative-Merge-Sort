#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char merge(double arr[], unsigned long long Left, unsigned long long Mid, unsigned long long Right)
{
    unsigned long long i, j, k;
    unsigned long long n1, n2;
    double left[(n1 = Mid - Left + 1)];
    double right[(n2 = Right - Mid)];

    for (i = 0; i < n1; i++)
    {
        left[i] = arr[Left + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = arr[Mid + j + 1];
    }

    for (i = 0, j = 0, k = Left; i < n1 && j < n2; k++)
    {
        if (right[j] < left[i])
        {
            arr[k] = right[j];
            j++;
        }
        else
        {
            arr[k] = left[i];
            i++;
        }
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    return 0;
}

unsigned char mergeSort(double arr[], unsigned long long Index, unsigned long long Length)
{
    unsigned long long size, left, mid, right, cache;

    cache = Length - 1;

    for (size = 1; size < Length; size *= 2)
    {
        for (left = Index; left < cache; left += size * 2)
        {
            if (cache < (mid = left + size - 1))
            {
                mid = cache;
            }
            if (cache < (right = left + size * 2 - 1))
            {
                right = cache;
            }

            merge(arr, left, mid, right);
        }
    }

    return 0;
}

int main(int argc, char* *argv)
{
    srand(time(NULL));

    double arr[100];

    for (int i = 0; i < sizeof(arr) / sizeof(double); i++)
    {
        arr[i] = rand() % 90 + 10;
    }

    mergeSort(arr, 0, sizeof(arr) / sizeof(double));

    for (int i = 0; i < sizeof(arr) / sizeof(double); i++)
    {
        printf("%lf ", arr[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }

    for (int i = 0; i < sizeof(arr) / sizeof(double) - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            return 1;
        }
    }

    return 0;
}