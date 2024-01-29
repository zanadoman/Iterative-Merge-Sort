#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char merge(double arr[], unsigned long long Left, unsigned long long Middle, unsigned long long Right)
{
    unsigned long long i, j, k, n1, n2;
    double* left;
    double* right;

    if ((left = (double*)malloc(sizeof(double) * (n1 = Middle - Left + 1))) == NULL)
    {
        printf("merge(): Memory allocation failed\nParams: arr: %p, Left: %llu, Middle: %lld, Right: %lld", arr, Left, Middle, Right);
        exit(1);
    }
    if ((right = (double*)malloc(sizeof(double) * (n2 = Right - Middle))) == NULL)
    {
        printf("merge(): Memory allocation failed\nParams: arr: %p, Left: %llu, Middle: %lld, Right: %lld", arr, Left, Middle, Right);
        exit(1);
    }

    for (i = 0; i < n1; i++)
    {
        left[i] = arr[Left + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = arr[Middle + j + 1];
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

    free(left);
    free(right);

    return 0;
}

unsigned char mergeSort(double arr[], unsigned long long From, unsigned long long Until)
{
    unsigned long long size, left, middle, right, cache;

    cache = Until - 1;

    for (size = 1; size < Until; size *= 2)
    {
        for (left = From; left < cache; left += size * 2)
        {
            if (cache < (middle = left + size - 1))
            {
                middle = cache;
            }
            if (cache < (right = left + size * 2 - 1))
            {
                right = cache;
            }

            merge(arr, left, middle, right);
        }
    }

    return 0;
}

int main()
{
    srand(time(NULL));

    double arr[100];

    for (unsigned int i = 0; i < sizeof(arr) / sizeof(double); i++)
    {
        arr[i] = rand() % 90 + 10;
    }

    mergeSort(arr, 0, sizeof(arr) / sizeof(double));

    for (unsigned int i = 0; i < sizeof(arr) / sizeof(double); i++)
    {
        printf("%lf ", arr[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }

    for (unsigned int i = 0; i < sizeof(arr) / sizeof(double) - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            return 1;
        }
    }

    return 0;
}