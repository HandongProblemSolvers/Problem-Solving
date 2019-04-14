#include <stdio.h>
#include <string.h>

int main(void) {
        char input_arr[5005];
        int arr_length;
        int temp = 0;
        int index = 0;
        int max = 0;
        int result = 0;

        scanf("%s", input_arr);
        arr_length = strlen(input_arr);

        for(int i = 1; i < arr_length; i++) {
                index = i;

                for(int j = 0; j < arr_length - i; j++) {
                        if(input_arr[j] == input_arr[index]) {
                                temp++;
                                if(temp > max) max = temp;
                        } else {
                                temp = 0;
                        }

                        index++;
                }

                if(max > result) result = max;

                max = 0;
                temp = 0;
        }

        printf("%d", result);
}
