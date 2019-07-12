#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_SIZE 81

typedef enum {
    false, true
} bool;

char** malloc2D(int row, int col);
void free2D(char **str, int n);
bool check(char **str, int n);
bool surprising(char *str);
void displayAns(char *str, bool isSurprising);

int main()
{
    char str[MAX_SIZE];

    while (1) {
        scanf("%s", str);

        if (str[0] == '*')
            break;

        displayAns(str, surprising(str));
    }
    return 0;
}

char** malloc2D(int row, int col)
{
    char **arr;

    arr = (char **) malloc(row * sizeof(char *));

    for (int i = 0; i < row; i++) 
        arr[i] = (char *) malloc(col * sizeof(char));

    return arr;    
}

void free2D(char **arr, int row)
{
    for (int i = 0; i < row; i++) 
        free(arr[i]);   

    free(arr);    
}

bool check(char **str, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!strncmp(str[i], str[j], 2))
                return false;
        }
    }
    return true;
}

bool surprising(char *str) 
{
    int len = strlen(str);

    for (int i = 0; i <= len - 2; i++) {
        char **sub = malloc2D(len - (i + 1), 2);
        int k = 0;
        bool isDS;

        for (int j = 0; j < len - (i + 1); j++) {
            sub[k][0] = str[j];
            sub[k++][1] = str[j + i + 1];
        }
        isDS = check(sub, k);

        free2D(sub, len - (i + 1));  

        if (!isDS) 
            return false;  
    }
    return true;
}

void displayAns(char *str, bool isSurprising)
{
    if (isSurprising)
        printf("%s is surprising.\n", str);
    else 
        printf("%s is NOT surprising.\n", str);    
}