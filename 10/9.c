#include<stdio.h>

int main(void)
{
	int list[10] = {0};
	int number;
	int out = 0;
	scanf("%d", &number);
	for(;number != 0; number /= 10){
		if(!list[number % 10]){
			list[number % 10] ++;
			out = (out * 10) + (number % 10);
		}
	}
	printf("%d", out);
	return 0;
}