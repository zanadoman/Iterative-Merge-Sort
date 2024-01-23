#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int merge(int arr[], int Left, int Mid, int Right)
{
    int i, j, k;
    int n1, n2;
    int left[n1 = Mid - Left + 1];
    int right[n2 = Right - Mid];

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

int mergeSort(int arr[], int Index, int Length)
{
    int size, left, mid, right, cache;

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

    int arr[100];

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        arr[i] = rand() % 90 + 10;
    }

    mergeSort(arr, 0, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }

    for (int i = 0; i < sizeof(arr) / sizeof(int) - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            return 1;
        }
    }

    return 0;
}