#include <stdio.h>
#include <malloc.h>

typedef enum {
    false, true
} bool;

#define MAX_SIZE 100000
#define ASCII_DIFF 48

bool descen(char *arr, int a, int b);
void swap(char *arr, int a, int b);
void sink(char *arr, int n, int k, bool (*fp) (char *, int, int));
void heapify(char *arr, int n, bool (*fp) (char *, int, int));
void delete(char *arr, int n, bool (*fp) (char *, int, int));
void heapsort(char *arr, int n, bool (*fp) (char *, int, int));
int maxNum(char *num, int n);
void displayArr(char *arr, int n);

int main()
{
    int count = 0;
    char *num;

    num = (char *) malloc ((MAX_SIZE + 1) * sizeof(char));
    
    for (int i = 1; i <= MAX_SIZE; i++) {
        scanf("%c", &num[i]);

        if (num[i] == '\n')
            break;

        count++;    
    }
    
    if (!maxNum(num, count))
        printf("-1\n");
    else
        displayArr(&num[1], count);    

    free(num);

    return 0;
}

bool descen(char *arr, int a, int b)
{
    return arr[a] < arr[b];
}

void swap(char *arr, int a, int b)
{
    char temp = arr[a];

    arr[a] = arr[b];
    arr[b] = temp;
}

void sink(char *arr, int n, int k, bool (*fp) (char *, int, int))
{
    while (2 * k <= n) {
        int cmp;

        if (2 * k + 1 > n || fp(arr, 2 * k, 2 * k + 1))
            cmp = 2 * k;
        else 
            cmp = 2 * k + 1;  

        if (fp(arr, k, cmp))
            break;
        
        swap(arr, k, cmp);

        k = cmp;           
    }
}

void heapify(char *arr, int n, bool (*fp) (char *, int, int))
{
    for (int i = n / 2; i >= 1; i--) 
        sink(arr, n, i, fp);
}

void delete(char *arr, int n, bool (*fp) (char *, int, int))
{
    swap(arr, 1, n);
    sink(arr, n - 1, 1, fp);
}

void heapsort(char *arr, int n, bool (*fp) (char *, int, int))
{
    heapify(arr, n, fp);

    for (int i = n; i >= 1; i--) 
        delete(arr, i, fp);    
}

int maxNum(char *num, int n)
{
    int sum = 0;
    bool hasZero = false;

    for (int i = 1; i <= n; i++) {
        sum += num[i] - ASCII_DIFF;

        if (num[i] - ASCII_DIFF == 0)
            hasZero = true;        
    }

    if (!hasZero || sum % 3 != 0) 
        return 0;

    heapsort(num, n, descen);

    /* 
    for (int i = 1; i <= size; i++)     
        printf("%d ", num[i]);
    putchar('\n');
    */
    
    return 1;
}

void displayArr(char *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%c", arr[i]);

    putchar('\n');    
}