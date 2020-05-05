#include <stdio.h>
#include <stdlib.h>

void createRandomVetor(int *vetor, int size)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        vetor[i] = rand() % size;
    }
}

void printVetor(int *vetor, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (i == 0)
        {
            printf("\n\t[ %i, ", vetor[i]);
        }
        else if (i == (size - 1))
        {
            printf("%i ]\n", vetor[i]);
        }
        else
        {
            printf("%i, ", vetor[i]);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *vetor, int left, int mid, int right)
{

    int size1 = right - left + 1;
    int size2 = right - mid;
    int *temp;
    temp = (int *)malloc(size1 * sizeof(int));

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (vetor[i] <= vetor[j])
        {
            temp[k] = vetor[i];
            k += 1;
            i += 1;
        }
        else
        {
            temp[k] = vetor[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = vetor[i];
        k++;
        i++;
    }

    while (j <= right)
    {
        temp[k] = vetor[j];
        k++;
        j++;
    }

    for (i = left; i <= right; i++)
    {
        vetor[i] = temp[i - left];
    }
}

void mergeSort(int *vetor, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(vetor, left, mid);
        mergeSort(vetor, mid + 1, right);
        merge(vetor, left, mid, right);
    }
}
