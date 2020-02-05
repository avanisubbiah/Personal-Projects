#include <stdio.h>

int main (void)
{
    int arrSize = 10;
    int arr[arrSize];
    int j = arrSize;

    for (int i=0; i<arrSize; i++)
    {
        arr[i] = arrSize-j;
        j = j - 1;
    }

    printf("Non-sorted:\n");

    for (int i=0; i<arrSize; i++)
    {
        printf("%d", arr[i]);
    }

    printf("\n");

    for (int i=0; i<arrSize; i++)
    {
        for (int j=0; j<(arrSize-1); j++)
        {
            if (arr[j] < arr [j+1])
            {
                int temp;
                temp= arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } 
        }
    }

    printf("Bubble Sorted Decreasing Order:\n");

    for (int i=0; i<arrSize; i++)
    {
        printf("%d", arr[i]);
    }

    printf("\n");

}