#include<stdio.h>
#include<stdint.h>

int main(void)
{
	int input;
	while(scanf("%d", &input)){
		if(input == 0)
		{
			printf("0");
		}
		for(;input != 0; input /= 10){
			printf("%c",input % 10 + '0');
		}
		printf("\n");
	}
	return 0;
}