#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 1000001

int minArrow(int *hei, int n);

int main()
{   
    int *hei;
    int N;
    int i;

    scanf("%d", &N);

    hei = (int *) malloc(N * sizeof(int));

    for (i = 0; i < N; i++) 
        scanf("%d", &hei[i]);
    
    printf("%d\n", minArrow(hei, N));

    free(hei);

    return 0;
}

int minArrow(int *hei, int n)
{
    int *visited;
    int count = 0;
    int i;

    visited = (int *) malloc(MAX_SIZE * sizeof(int));

    for (i = 0; i < MAX_SIZE; i++)
        visited[i] = 0;
    
    for (i = 0; i < n; i++) {
        if (!visited[hei[i]])
            count++;
        else 
            visited[hei[i]]--;
        
        visited[hei[i] - 1]++;
    }            
    free(visited);

    return count;
}

