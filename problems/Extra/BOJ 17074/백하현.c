#include <stdio.h>
#include <malloc.h>

int sorted(int *arr, int n);
int numSort(int *arr, int n);

int main()
{
    int *arr;
    int N;

    scanf("%d", &N);

    arr = (int *) malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", numSort(arr, N));    

    free(arr);

    return 0;
}

int sorted(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            return i;
    }
    return -1;
}

int numSort(int *arr, int n)
{
    int index = sorted(arr, n);

    if (index < 0)
        return n;
    
    int count = 0;
    
    if (index == 0) {
        if (sorted(arr + 1, n - 1) < 0) 
            count++;

        arr[index + 1] = arr[index + 2];

        if (sorted(arr, n) < 0)
            count++;     
    }
    else {
        int temp = arr[index];

        arr[index] = arr[index + 1];

        if (sorted(arr + index - 1, n - index + 1) < 0)
            count++;

        arr[index + 1] = temp;
        arr[index] = temp;

        if (sorted(arr + index, n - index) < 0)
            count++;
    } 
    return count;
}