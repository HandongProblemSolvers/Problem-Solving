#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100
#define START_SIZE 3
#define MAX_TIME 100
#define MAX_NUM 100
#define INF MAX_NUM + 1

typedef enum {
    false, true
} bool;

int** malloc2D(int row, int col);
void free2D(int **arr, int row);
void init(int *arr, int n);
int max(int a, int b);
int rmax(int **arr);
int cmax(int **arr);
void ccopy(int *dest, int **arr, int n, int c);
void rcopy(int *dest, int *src, int n);
void record(int *count, int *arr, int n);
bool ascen(int *arr, int a, int b, int *count);
void swap(int *arr, int a, int b);
void sink(int *arr, int n, int k, int *count, bool (*fp) (int *, int, int, int *));
void heapify(int *arr, int n, int *count, bool (*fp) (int *, int, int, int *));
void delete(int *arr, int n, int k, int *count, bool (*fp) (int *, int, int, int *));
void heapsort(int *arr, int n, int *count, bool (*fp) (int *, int, int, int *));
void removeDup(int *arr, int n, int *visited);
void addNum(int *arr, int n, int *count);
void paste(int **arr, int n, int c, int *src);
void update(int **arr, int *count, int *visited, int rm, int cm);
int time(int **arr, int r, int c, int t);

int main()
{
    int **arr;
    int r, c, k;

    arr = malloc2D(MAX_SIZE, MAX_SIZE + 1);

    for (int i = 0; i < MAX_SIZE; i++) 
        init(arr[i], MAX_SIZE + 1);

    scanf("%d %d %d", &r, &c, &k);

    for (int i = 0; i < START_SIZE; i++) {
        for (int j = 1; j <= START_SIZE; j++)
            scanf("%d", &arr[i][j]);
    }
    printf("%d\n", time(arr, r, c, k));

    free2D(arr, MAX_SIZE);

    return 0;
}

int** malloc2D(int row, int col)
{
    int **arr;

    arr = (int **) malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++) 
        arr[i] = (int *) malloc(col * sizeof(int));

    return arr;    
}

void free2D(int **arr, int row)
{
    for (int i = 0; i < row; i++)
        free(arr[i]);

    free(arr);    
}

void init(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int rmax(int **arr) 
{
    for (int i = 0; i < MAX_SIZE; i++) {
        bool isEnd = true;

        for (int j = 1; j <= MAX_SIZE; j++) {
            if (arr[i][j])
                isEnd = false;
        }

        if (isEnd)
            return i;
    }
    return MAX_SIZE;
}

int cmax(int **arr)
{
    for (int i = 1; i <= MAX_SIZE; i++) {
        bool isEnd = true;

        for (int j = 0; j < MAX_SIZE; j++) {
            if (arr[j][i])
                isEnd = false;
        }

        if (isEnd)
            return i - 1;
    }
    return MAX_SIZE;
}

void rcopy(int *dest, int *src, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void ccopy(int *dest, int **arr, int n, int c)
{
    for (int i = 0; i < n; i++) 
        dest[i] = arr[i][c];
}

void record(int *count, int *arr, int n)
{
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
}

bool ascen(int *arr, int a, int b, int *count)
{   
    if (count[arr[a]] == count[arr[b]])
        return arr[a] > arr[b];
    else     
        return count[arr[a]] > count[arr[b]];
}

void swap(int *arr, int a, int b)
{
    int temp = arr[a];

    arr[a] = arr[b];
    arr[b] = temp;
}

void sink(int *arr, int n, int k, int *count, bool (*fp) (int *, int, int, int *))
{
    while (2 * k <= n) {
        int cmp;

        if (2 * k + 1 > n || ascen(arr, 2 * k, 2 * k + 1, count))
            cmp = 2 * k;
        else 
            cmp = 2 * k + 1;

        if (!ascen(arr, k, cmp, count))
            swap(arr, k, cmp);
        else 
            break;

        k = cmp;
    }
}

void heapify(int *arr, int n, int *count, bool (*fp) (int *, int , int, int *))
{
    for (int i = n / 2; i >= 1; i--)
        sink(arr, n, i, count, fp);
}

void delete(int *arr, int n, int k, int *count, bool (*fp) (int *, int , int, int *))
{
    swap(arr, k, n);
    sink(arr, n - 1, k, count, fp);
}

void heapsort(int *arr, int n, int *count, bool (*fp) (int *, int, int, int *))
{
    heapify(arr, n, count, fp);

    for (int i = n; i >= 1; i--) 
        delete(arr, i, 1, count, fp);
}

void removeDup(int *arr, int n, int *visited)
{
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] && !visited[arr[i] - 1]) {
            arr[count] = arr[i];
            visited[arr[i] - 1] = 1;
            count++;
        }
    }

    for (int i = count; i < n; i++) 
        arr[i] = 0;
}

void addNum(int *arr, int n, int *count)
{
    int *dest;
    int index = 0;
    
    dest = (int *) malloc(n * sizeof(int));
    
    rcopy(dest, arr, n);
    
    for (int i = 0; index < n && dest[index]; i++) {
        if (i % 2 == 0) 
            arr[i] = dest[index];
        else {
            arr[i] = count[dest[index]];
            index++;
        }   
    }
    free(dest);
}

void paste(int **arr, int n, int c, int *src)
{
    for (int i = 0; i < MAX_SIZE; i++) 
        arr[i][c] = src[i];
}

void update(int **arr, int *count, int *visited, int rm, int cm)
{

    if (rm >= cm) {
        for (int i = 0; i < MAX_SIZE; i++) {
            count[0] = INF;
            init(&count[1], MAX_NUM);
            init(visited, MAX_NUM);

            record(count, &arr[i][1], rm);
            heapsort(arr[i], rm, count, ascen);
            removeDup(&arr[i][1], rm, visited);
            addNum(&arr[i][1], rm, count);  
        }
    }
    else {
        int *dest;

        dest = (int *) malloc((MAX_SIZE + 1) * sizeof(int));

        for (int i = 1; i <= MAX_SIZE; i++) {
            count[0] = INF;
            init(&count[1], MAX_NUM);
            init(visited, MAX_NUM); 
            init(dest, MAX_SIZE + 1);

            ccopy(&dest[1], arr, cm, i);
            record(count, &dest[1], cm);
            heapsort(dest, cm, count, ascen);
            removeDup(&dest[1], cm, visited);
            addNum(&dest[1], cm, count);   
            paste(arr, cm, i, &dest[1]);
        }
        free(dest);
    }
}

int time(int **arr, int r, int c, int t)
{
    int *count, *visited;
    int r_max = 0, c_max = 0;

    count = (int *) malloc((MAX_NUM + 1) * sizeof(int));
    visited = (int *) malloc(MAX_NUM * sizeof(int));

    for (int i = 0; i <= MAX_TIME; i++) {
        if (arr[r - 1][c] == t) {
            free(count);
            free(visited);

            return i;
        }
        r_max = max(rmax(arr), r_max);
        c_max = max(cmax(arr), c_max);
    
        update(arr, count, visited, r_max, c_max);  
        
        /*   
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                printf("%d ", arr[i][j]);
            putchar('\n');    
        }
        */
    }
    free(count);
    free(visited);

    return -1;
}