#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char str[100] = {};
	while(gets(str) != NULL){
		int len = strlen(str);
		for(int i = 0; i < len; i++){
			printf("%c",str[i]);
			if(((i + 1) % 8) == 0)
				printf("\n");
		}
		for(int i = len % 8; i > 0 && i < 8; i++){
			printf("0");
		}
		printf("\n");
	}
	return 0;
}