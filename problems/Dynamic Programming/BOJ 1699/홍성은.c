#include <stdio.h>
#include <math.h>

int square(int * arr, int x);

int main(void) {
        int input_num;
        int dp_arr[100000];

        scanf("%d", &input_num);

        for(int i = 0; i < input_num + 1; i++) {
                dp_arr[i] = -1;
        }

        for(int i = 0; pow(i, 2) <= input_num; i++) {
                dp_arr[(int)pow(i, 2)] = 1;
        }

        for(int i = 0; i < input_num + 1; i++) {
                square(dp_arr, i);
        }

        printf("%d", dp_arr[input_num]);

}

int square(int * arr, int x) {
        int min = x;

        for(int i = 1; pow(i, 2) < x; i++) {
                if(min > arr[x - (i * i)] + 1) {
                        min = arr[x - (i * i)] + 1;
                }
        }

        if(arr[x] != -1) {
                if(arr[x] > min) arr[x] = min;
        } else arr[x] = min;

        return arr[x];
}
