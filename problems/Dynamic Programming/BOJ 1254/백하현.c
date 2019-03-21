#include <stdio.h>
#include <string.h>

#define MAX_NUM 1000

int palinlen(char str[]);

int main()
{
    char S[MAX_NUM];

    scanf("%s", S);

    printf("%d\n", palinlen(S));

    return 0;
}

int palinlen(char str[])
{
    int std_index;
    int len;
    int dual, single;
    int i;

    len = strlen(str);
    
    if (len % 2 == 0) 
        std_index = len / 2;
    else
        std_index = len / 2 + 1;
        
    while (str[std_index] != '\0') {
        for (i = 0; str[std_index + i] != '\0'; i++) {
            if (str[std_index + i] != str[std_index - (i + 1)])
                break;
        }

        if (str[std_index + i] == '\0') {
            dual =  2 * std_index;

            break;
        }
        std_index++;    
    }

    std_index = len / 2;    

    while (str[std_index + 1] != '\0') {
        for (i = 1; str[std_index + i] != '\0'; i++) {
            if (str[std_index - i] != str[std_index + i]) 
                break;
        }

        if (str[std_index + i] == '\0') 
            break;

        std_index++;    
    }
    single = 2 * std_index + 1;

    if (dual < single)
        return dual;
    else
        return single;   
}
    
