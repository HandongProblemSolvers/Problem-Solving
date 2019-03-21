#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char input_str[1000];
	char compare_str[1000];
	int match_point = 0;
	int total_length = 0;
	int flag = 0;
	int str_length = 0;
		
	scanf("%s", input_str);

	str_length = strlen(input_str);
	
	for(int i = 0; i < str_length; i++) {
		compare_str[str_length - (i + 1)] = input_str[i];
	}

	for(int i = 0; i < str_length; i++) {
		if(flag == 1) break;		

		if(compare_str[0] != input_str[i]) continue;
		else match_point = i; // 같을 때
		
		if(match_point == (str_length - 1)) {
			total_length = str_length + (str_length - 1);
			break;
		}

		for(int j = match_point + 1; j < str_length; j++) {
			if(input_str[j] == compare_str[j - match_point]) {
				flag = 1; 
				continue;
			}
			else {
				flag = 0;
				break;
			}
		}
	}

	if(total_length == 0) total_length += str_length + match_point;

	printf("%d", total_length);

	return 0;
}
