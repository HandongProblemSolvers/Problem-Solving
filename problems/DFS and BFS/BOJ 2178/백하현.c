#include <stdio.h>
#include <malloc.h>

#define MAX_NUM 10000

typedef struct {
    int *queue;
    int N;
    int M;
    int head, tail;
    int size;
} QUEUE;

void distribute(QUEUE *q, char **temp, int maze[][100]);
void InitQueue(QUEUE *q);
int InQueue(QUEUE *q, int num);
int OutQueue(QUEUE *q);
int FindMinWay(QUEUE *q, int maze[][100]);

int main()
{                                                                                                                                                                                                                                                                                                                       
    QUEUE *q;
    char *temp[100];
    int maze[100][100];
    int N, M;
    int i;

    q = (QUEUE *) malloc(sizeof(QUEUE));
    
    scanf("%d %d", &q->N, &q->M);

    for (i = 0; i < q->N; i++) { 
        temp[i] = (char *) malloc(q->M * sizeof(char));

        scanf("%s", temp[i]);
    }    
    distribute(q, temp, maze);
    InitQueue(q);

    printf("%d\n", FindMinWay(q, maze));

    for (i = 0; i < q->N; i++) 
        free(temp[i]);
        
    free(q->queue);
    free(q);

    return 0;
}

void distribute(QUEUE *q, char **temp, int maze[][100])
{
    int i, j;

    for (i = 0; i < q->N; i++) {
        for (j = 0; j < q->M; j++) 
            maze[i][j] = (int) temp[i][j] - 48;
    }
}

void InitQueue(QUEUE *q)
{   
    q->size = q->N * q->M; 
    
    q->queue = (int *) malloc(q->size * sizeof(int));
    q->head = 0;
    q->tail = 0; 
}

int InQueue(QUEUE *q, int num)
{   
    if (q->tail == q->size - 1 && q->head == 0) 
        return 0;
    else {
        if (q->tail == q->size - 1) 
            q->tail = (q->tail + 1) % q->size;
        
        q->queue[q->tail++] = num;
        
        return num;
    }
}

int OutQueue(QUEUE *q)
{   
    int val;

    if (q->head == q->tail)
        return 0;
    else {
        val = q->queue[q->head++];
        
        if (q->head == q->size - 1) {
            q->head++;
            q->head %= q->size;
        }
        return val;
    }
}

int FindMinWay(QUEUE *q, int maze[][100])
{   
    int *temp;
    int i_count = -1, h_count = 0;
    int height = 0, sum = 0, t_sum = 1;
    int i= 0, j = 0, k = 0;
    
    temp = (int *) malloc(MAX_NUM * sizeof(int));

    InQueue(q, maze[i][j]);
    maze[i][j] = 2;
    temp[k++] = 100 * i + j;

    while (1) {
        do { 
            i_count++;
        } while (!OutQueue(q));

        j = temp[i_count] % 100;
        temp[i_count] /= 100;
        i = temp[i_count];
         
        if (i == q->N - 1 && j == q->M - 1)
            break;  
      
        if (maze[i][j + 1] != 2 && j < q->M - 1) {
            sum += InQueue(q, maze[i][j + 1]);
            temp[k++] = 100 * i + j + 1; 
            maze[i][j + 1] = 2;
            
        }

        if (maze[i][j - 1] != 2 && j > 0) {
            sum += InQueue(q, maze[i][j - 1]);
            temp[k++] = 100 * i + j - 1;
            maze[i][j - 1] = 2;
        }

        if (maze[i + 1][j] != 2 && i < q->N - 1) {
            sum += InQueue(q, maze[i + 1][j]);
            temp[k++] = 100 * (i + 1) + j;
            maze[i + 1][j] = 2;
        }

        if (maze[i - 1][j] != 2 && i > 0) {
            sum += InQueue(q, maze[i - 1][j]);
            temp[k++] = 100 * (i - 1) + j;
            maze[i - 1][j] = 2;
        }
        h_count++;

        if (h_count == t_sum) {
            t_sum = sum;
            sum = 0;
            h_count = 0;
            height++;
        }
    }
    free(temp);

    return height + 1;
}
