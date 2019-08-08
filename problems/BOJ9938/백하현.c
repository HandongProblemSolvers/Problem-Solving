#include <stdio.h>
#include <malloc.h>

typedef enum {
    false, true
} bool;

void initSet(int *set, int *visited, int n);
int find(int *set, int val);
void unions(int *set, int a, int b);
bool store(int *set, int *visited, int a, int b);
void displayAns(bool isStored);

int main()
{
    int *set, *visited;
    int N, L;    

    scanf("%d %d", &N, &L);

    set = (int *) malloc(L * sizeof(int));
    visited = (int *) malloc(L * sizeof(int));

    initSet(set, visited, L);

    for (int i = 0; i < N; i++) {
        int A, B;

        scanf("%d %d", &A, &B);
        displayAns(store(set, visited, A, B));
    }
    free(set);
    free(visited);

    return 0;
}

void initSet(int *set, int *visited, int n)
{
    for (int i = 0; i < n; i++) { 
        set[i] = i + 1;
        visited[i] = 0;
    }
}

int find(int *set, int val)
{
    if (set[val - 1] == val)
        return val;

    return set[val - 1] = find(set, set[val - 1]);
}

void unions(int *set, int a, int b)
{
    set[find(set, b) - 1] = find(set, a);
}

bool store(int *set, int *visited, int a, int b)
{
    int ar = find(set, a);
    int br = find(set, b);

    //printf("%d %d\n", ar, br);

    if (!visited[a - 1]) {
        visited[a - 1] = 1;

        if (ar != br)
            unions(set, b, a);     
    }
    else if (!visited[b - 1]) {
        visited[b - 1] = 1;

        if (ar != br)
            unions(set, a, b);     
    }
    else if (!visited[ar - 1]) { 
        visited[ar - 1] = 1;

        if (ar != br)
            unions(set, b, a);  
    }
    else if (!visited[br - 1]) {
        visited[br - 1] = 1;
        
        if (ar != br)
            unions(set, a, b);
    }
    else 
        return false;

    return true;        
}

void displayAns(bool isStored)
{
    if (isStored)
        printf("LADICA\n");
    else
        printf("SMECE\n");    
}